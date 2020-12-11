#include "ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsrand(QTime::currentTime().msec());

    ui->setupUi(this);
    pictures.load();

    ui->labelStatus->setStyleSheet("QLabel { color : #00157f; }");
    ui->labelOpponent->setStyleSheet("QLabel { color : #00157f; }");
    ui->labelOpponent->clear();
    model = new Model;
    controller = new Controller(model);

    connect(controller, SIGNAL(stateChanged()), this, SLOT(redraw()));
    connect(controller, SIGNAL(gameResult(GameResult)), this, SLOT(showGameResult(GameResult)));
    connect(controller, SIGNAL(gameError(GameErrorMessage)), this, SLOT(showGameError(GameErrorMessage)));
    connect(controller, SIGNAL(gameOpponent(QString)), this, SLOT(changeGameOpponent(QString)));

    this->redraw();
}

MainWindow::~MainWindow()
{
    delete controller;
    delete model;
    delete ui;
}

void MainWindow::setStatus(const QString& status)
{
    ui->labelStatus->setText(tr("Status: ") + status);
}

void MainWindow::changeGameOpponent(const QString& name)
{
    ui->labelOpponent->setText(tr("Opponent: ") + name);
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    const int deltaY = this->centralWidget()->y();

    QPainter painter(this);

    painter.drawImage(FIELD_X, FIELD_Y + deltaY, myFieldImage());
    painter.drawImage(FIELD_X, FIELD_Y + deltaY, enemyFieldImage());

    switch (controller->getState())
    {
    case ST_WAITTING_FOR_THE_START:
        setStatus(tr("waiting for the start"));
        break;

    case ST_MAKING_STEP:
        setStatus(tr("your step"));
        break;

    case ST_WAITING_STEP:
        setStatus(tr("wait for enemy"));
        break;
    }
}

QImage MainWindow::myFieldImage()
{
    return getFieldImage(0);
}

QImage MainWindow::enemyFieldImage()
{
    return getFieldImage(1);
}

QImage MainWindow::getFieldImage(char fld)
{
    QImage image(FIELD_WIDTH, FIELD_HEIGHT, QImage::Format_ARGB32);
    Cell cell;
    image.fill(0);
    QPainter painter(&image);

    double cfx = 1.0 * FIELD_WIDTH / 10.0;
    double cfy = 1.0 * FIELD_HEIGHT / 10.0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // fld == 0 means me; fld == other means enemy
            cell = model->getCell(i, j);
            QString imgName = "";
            switch (cell)
            {
            case CL_X:
                imgName = "standart_blue";
                break;
            case CL_O:
                imgName = "standart_red";
                break;
            case CL_CATCH_X:
                imgName = "catch_blue";
                break;
            case CL_CATCH_O:
                imgName = "catch_red";
                break;
            default:
                break;
            }
            if (imgName != "")
            {
                painter.drawImage(i * cfx, j * cfy, pictures.get(imgName));
            }
        }
    }

    return image;
}

void MainWindow::mousePressEvent(QMouseEvent* ev)
{
    QPoint pos = ev->pos();
    pos.setY(pos.y() - this->centralWidget()->y());
    controller->onMousePressed(pos);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    controller->onGameQuit();
    event->accept();
}

void MainWindow::on_actionStart_triggered()
{
    ConnectionInfoDialog* connectionDialog = new ConnectionInfoDialog(this);

    connectionDialog->setModal(true);
    connectionDialog->setAddressString(
        controller->getServerAddress(),
        controller->getServerPort()
    );
    connectionDialog->setLogin(controller->getUserLogin());

    connectionDialog->setPassword(controller->getUserPassword());

    if (connectionDialog->exec() != QDialog::Accepted)
        return;

    controller->setConnectionInfo(
        connectionDialog->getAddress(),
        connectionDialog->getPort(),
        connectionDialog->getLogin(),
        connectionDialog->getPassword()
    );
    controller->onGameStart();
    redraw();
}

void MainWindow::redraw()
{
    if (controller->getState() == ST_WAITTING_FOR_THE_START)
    {
        ui->labelOpponent->clear();
    }

    if (controller->getState() == ST_WAITTING_FOR_THE_START)
    {
        ui->actionStart->setDisabled(false);
        ui->actionLeave->setDisabled(true);
    }
    else
    {
        ui->actionStart->setDisabled(true);
        ui->actionLeave->setDisabled(false);
    }

    this->update();
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::showGameResult(GameResult result)
{
    if (result == GR_NONE)
    {
        return;
    }

    QString messageString = result == GR_WON ? tr("You win!") : tr("You lose!");
        
    this->update();
    QMessageBox::information(this, tr("Game result"), messageString);
}

void MainWindow::showGameError(GameErrorMessage message)
{
    QString messageString;

    switch (message)
    {
    case GEM_WRONG_USER:
        messageString = tr("Wrong user passed!");
        break;

    case GEM_ALREADY_CONNECTED:
        messageString = tr("You are already connected!");
        break;

    case GEM_SERVER_ERROR:
        messageString = tr("Server error!");
        break;

    case GEM_SERVER_CONNECTION_REFUSED:
    case GEM_SERVER_UNAVAILABLE:
        messageString = tr("Cannot connect to the server.");
        break;

    case GEM_SERVER_CONNECTION_TIMEOUT:
        messageString = tr("Server unavailable.");
        break;

    default:
        return;
    }

    this->update();
    QMessageBox::information(this, tr("Game Info"), messageString);
}

void MainWindow::on_actionLeave_triggered()
{
    controller->onGameQuit();
    QMessageBox::information(
        this,
        tr("Game Info"),
        tr("You have disconnected!")
    );

    redraw();
}