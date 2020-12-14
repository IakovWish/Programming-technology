#pragma once
#include <QObject>
#include <QPoint>
#include <QTcpSocket>
#include <QRegExp>
#include <QMessageBox>
#include <QFile>
#include <QRegExp>
#include "Model.h"
#include "Utility.h"
#include "ConnectionInfoDialog.h"

enum class GameResult
{
    GR_NONE = 0,
    GR_WON = 1,
    GR_LOST = -1
};

enum class GameErrorMessage
{
    GEM_UNKNOWN = -1,
    GEM_NONE = 0,
    GEM_ALREADY_CONNECTED,
    GEM_WRONG_USER,
    GEM_SERVER_ERROR,
    GEM_SERVER_CONNECTION_REFUSED,
    GEM_SERVER_CONNECTION_TIMEOUT,
    GEM_SERVER_UNAVAILABLE
};

class Controller: public QWidget
{
    Q_OBJECT
public:
    Controller( Model* model_);
    ~Controller();
    void onMousePressed( const QPoint& position);
    void onGameStart();
    void onGameQuit();
    void onGameSave(int i);
    void onGameDownload(int i);
    State getState() const;
    void setConnectionInfo(const QString& address, quint16 port, const QString& login, const QString& password, const QString& pref);
   
    QString getServerAddress() const;
    quint16 getServerPort() const;
    QString getUserLogin() const;
    QString getUserPassword() const;
    QString getUserPref() const;

signals:
    void stateChanged();
    void gameResult( GameResult result );
    void gameError( GameErrorMessage message );
    void gameOpponent( const QString& name );

private slots:
    void onDataReceived();
    void onConnected();
    void onError( QAbstractSocket::SocketError socketError );

private:
    void parseData( const QString& data );
    bool parsePing( const QString& data );
    bool parseFound( const QString& data );
    bool parseGo( const QString& data );
    bool parseGameResult( const QString& data );
    bool parseFields( const QString& data );
    bool parseErrorInfo( const QString& data );
    bool parseWrongStep( const QString& data );
    void readConfig();
    void saveConfig();
    bool checkError(const QString&,const QString&);
    void emitError(GameErrorMessage error);
    void markCell(int x, int y, Cell cell, bool atEnemyField = false);

private:
    QTcpSocket* client;
    Model* model;
    QHostAddress serverAddress;
    quint16 serverPort;
    bool connectionError;
};