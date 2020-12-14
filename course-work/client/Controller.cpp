#include <QAbstractSocket>
#include "Controller.h"

const QString& DEFAULT_CONFIG_FILE = "config.ini";
const quint16 DEFAULT_SERVER_PORT = 1234;
const quint16 DEFAULT_SERVER_TIMEOUT = 5000;

Controller::Controller( Model* model_):
    model( model_ ),
    serverAddress( QHostAddress::LocalHost ),
    serverPort( DEFAULT_SERVER_PORT )
{
    client = new QTcpSocket( this );
    connect(client, SIGNAL(readyRead()), this, SLOT(onDataReceived()));

    connect(client, SIGNAL(connected()), this, SLOT(onConnected()));

    connect(client, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

    readConfig();
}

Controller::~Controller()
{
    saveConfig();
}

void Controller::readConfig()
{
    if( !QFile::exists(DEFAULT_CONFIG_FILE) )
    {
        qDebug() << "Config file does not exists!";
        return;
    }

    QFile cf( DEFAULT_CONFIG_FILE );

    if (!cf.open(QFile::ReadOnly))
    {
        return;
    }

    QByteArray line;
    QRegExp rx( "(\\d+\\.\\d+\\.\\d+\\.\\d+):(\\d+):(\\w+):(.+):(\\w+):" );

    while( !cf.atEnd() )
    {
        line = cf.readLine();

        if (rx.indexIn(line) == -1)
        {
            continue;
        }

        qDebug() << "Setting connection info";
        setConnectionInfo(rx.cap(1), rx.cap(2).toUInt(), rx.cap(3), rx.cap(4), rx.cap(5));

        break;
    }

    cf.close();
}

void Controller::saveConfig()
{
    QFile cf( DEFAULT_CONFIG_FILE );

    if (!cf.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    cf.write(qPrintable(QString("%1:%2:%3:%4:%5:\n").arg(serverAddress.toString()).arg(serverPort).arg(model->getLogin()).arg(model->getPassword()).arg(model->getPref())));
    cf.close();
}

void Controller::onMousePressed( const QPoint& pos)
{
    if( model->getState() == State::ST_MAKING_STEP )
    {
        QPoint point = getFieldCoord(pos);

        QString cmd;
        cmd = QString( "step:%1:%2:" ).arg( point.x() ).arg( point.y() );
        qDebug() << cmd;
        client->write( cmd.toLocal8Bit() );

        model->setState(State::ST_WAITING_STEP);
        emit stateChanged();

        return;
    }
}

void Controller::onDataReceived()
{
    QString data;
    data = client->readAll();
    qDebug() << "Data:" << data;
    parseData( data );
    emit stateChanged();
}

void Controller::parseData( const QString& data )
{
    parseFound( data );
    parseWrongStep( data );
    parseFields( data );
    parseGo( data );
    parseGameResult( data );
    parseErrorInfo( data );
    parsePing( data );
}

bool Controller::parsePing( const QString& data )
{
    QRegExp rx( "ping:" );

    if( rx.indexIn(data) == -1 )
        return false;

    qDebug() << "Ping request";
    client->write("pong:\n");
    return true;
}

bool Controller::parseFound( const QString& data )
{
    QRegExp rx( "found:((\\w|\\d)+):" );

    if (rx.indexIn(data) == -1)
    {
        return false;
    }

    qDebug() << "Found opponent:" << rx.cap( 1 );
    emit gameOpponent( rx.cap(1) );
    return true;
}

bool Controller::parseGo( const QString& data )
{
    QRegExp rx( "go:" );

    if (rx.indexIn(data) == -1)
    {
        return false;
    }

    qDebug() << "Now making step!";
    model->setState(State::ST_MAKING_STEP);

    return true;
}

bool Controller::parseErrorInfo( const QString& data )
{
    if (checkError("wronguser:", data))
    {
        emitError(GameErrorMessage::GEM_WRONG_USER);
    }

    if (checkError("alreadyauth:", data))
    {
        emitError(GameErrorMessage::GEM_ALREADY_CONNECTED);
    }

    return true; //TODO: fix it
}

bool Controller::checkError(const QString& error, const QString& data)
{
    QRegExp rx( error );
    if (rx.indexIn(data) == -1)
    {
        return false;
    }
    return true;
}

void Controller::emitError(GameErrorMessage error)
{
    qDebug() << "Some error";
    model->setState(State::ST_WAITTING_FOR_THE_START);
    connectionError = true;
    emit gameError( error );
}

bool Controller::parseWrongStep( const QString& data )
{
    QRegExp rx( "wrongstep:" );

    if (rx.indexIn(data) == -1)
    {
        return false;
    }

    qDebug() << "Maked wrong step";
    model->setState(State::ST_MAKING_STEP );
    return true;
}

bool Controller::parseFields( const QString& data )
{
    QRegExp rx( "field(\\d):(\\w+):(\\d):(\\d):" );

    int pos = 0;
    while( (pos = rx.indexIn(data, pos)) != -1 )
    {
        const QString& type = rx.cap( 2 );
        int field = rx.cap( 1 ).toInt();
        int x = rx.cap( 3 ).toInt();
        int y = rx.cap( 4 ).toInt();

        Cell cell = type == "catched" ? Cell::CL_CATCH_X : Cell::CL_X;

        markCell(x, y, cell, field == 2);

        pos += rx.matchedLength();
    }

    return pos;
}

void Controller::markCell(int x, int y, Cell cell, bool atEnemyField)
{
    if (!atEnemyField)
    {
        cell = cell == Cell::CL_CATCH_X ? Cell::CL_CATCH_O : Cell::CL_O;
    }

    model->setCell(x, y, cell);
}

bool Controller::parseGameResult( const QString& data )
{
    QRegExp rx( "win:" );

    if( rx.indexIn(data) != -1 )
    {
        qDebug() << "We win!";
        emit gameResult(GameResult::GR_WON );
       
        model->setState(State::ST_WAITTING_FOR_THE_START);

        model->clearField();
        return true;
    }

    QRegExp rx2( "lose:" );

    if( rx2.indexIn(data) != -1 )
    {
        qDebug() << "We lose!";
        emit gameResult(GameResult::GR_LOST );

        model->setState(State::ST_WAITTING_FOR_THE_START);

        model->clearField();
        return true;
    }

    return false;
}

void Controller::onGameStart()
{
    if( client->state() == QAbstractSocket::ConnectedState )
    {
        emit gameError(GameErrorMessage::GEM_ALREADY_CONNECTED );
        return;
    }

    // hardcoded server address
    serverAddress = QHostAddress( "127.0.0.1" );

    client->connectToHost( serverAddress, serverPort );

    if( !client->waitForConnected(DEFAULT_SERVER_TIMEOUT) )
    {
        if (client->error() == QAbstractSocket::SocketTimeoutError)
        {
            emit gameError(GameErrorMessage::GEM_SERVER_CONNECTION_TIMEOUT);
        }

        return;
    }

    qDebug("Connected to host %s:%d as %s", qPrintable(serverAddress.toString()), serverPort, qPrintable(model->getLogin()));
}

void Controller::onGameQuit()
{
    if( client->state() == QAbstractSocket::ConnectedState )
    {
        qDebug() << "Disconnecting from host";
        client->write( "disconnect:" );
        client->flush();
        client->disconnectFromHost();

        model->clearField();
        model->setState(State::ST_WAITTING_FOR_THE_START);
    }
}

void Controller::onError( QAbstractSocket::SocketError socketError )
{
    qDebug() << client->errorString();

    if (model->getState() == State::ST_WAITING_STEP || model->getState() == State::ST_MAKING_STEP)
    {
        model->setState(State::ST_WAITTING_FOR_THE_START);
    }

    if (socketError == QAbstractSocket::ConnectionRefusedError)
    {
        emit gameError(GameErrorMessage::GEM_SERVER_CONNECTION_REFUSED);
    }

    if (socketError == QAbstractSocket::HostNotFoundError || socketError == QAbstractSocket::SocketTimeoutError)
    {
        emit gameError(GameErrorMessage::GEM_SERVER_UNAVAILABLE);
    }
}

void Controller::onConnected()
{
    QString response;
    QString request;
    connectionError = false;

    request = QString( "mbclient:2:%1:%2:%3:").arg(model->getLogin()).arg(model->getPassword()).arg(model->getPref());

    qDebug() << response;

    client->write( request.toLocal8Bit() );

    if (!client->waitForReadyRead(DEFAULT_SERVER_TIMEOUT))
    {
        return;
    }

    if (connectionError)
    {
        return;
    }

    response = client->readAll();
    qDebug() << response;

    request = "field:4:" + model->getField() + ":";
    client->write( request.toLocal8Bit() );

    qDebug() << request;
    model->setState(State::ST_WAITING_STEP );
}

State Controller::getState() const
{
    return model->getState();
}

void Controller::setConnectionInfo(const QString& address, quint16 port, const QString& login, const QString& password, const QString& pref)
{
    serverAddress = QHostAddress( address );
    serverPort = port;
    model->setLogin( login );
    model->setPassword( password );
    model->setPref(pref);
}

QString Controller::getServerAddress() const
{
    return serverAddress.toString();
}

quint16 Controller::getServerPort() const
{
    return serverPort;
}

QString Controller::getUserLogin() const
{
    return model->getLogin();
}

QString Controller::getUserPassword() const
{
    return model->getPassword();
}

QString Controller::getUserPref() const
{
    return model->getPref();
}