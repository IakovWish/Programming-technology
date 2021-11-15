#include "ui_mainwindow.h"
#include "mainwindow.h"

const QString& DEFAULT_SAVE_FILE_1 = "save1.txt";
const QString& DEFAULT_SAVE_FILE_2 = "save2.txt";
const QString& DEFAULT_SAVE_FILE_3 = "save3.txt";

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    qsrand(QTime::currentTime().msec());

    ui->setupUi(this);
    pictures.load();

    ui->labelStatus->setStyleSheet("QLabel { color : #00157f; }");
    ui->labelOpponent->setStyleSheet("QLabel { color : #00157f; }");
    ui->labelOpponent->clear();
    ui->labelYourLogin->setStyleSheet("QLabel { color : #00157f; }");
    ui->labelYourLogin->clear();
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

void MainWindow::setYourLogin()
{
    ui->labelYourLogin->setText(tr("Your login: ") + model->getLogin());
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

    painter.drawImage(FIELD_X, FIELD_Y + deltaY, getFieldImage());

    switch (controller->getState())
    {
    case State::ST_WAITTING_FOR_THE_START:
        setStatus(tr("press start"));
        break;

    case State::ST_MAKING_STEP:
        setStatus(tr("your step"));
        break;

    case State::ST_WAITING_STEP:
        setStatus(tr("wait for enemy"));
        break;
    }
}

QImage MainWindow::getFieldImage()
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
            cell = model->getCell(i, j);
            QString imgName = "";
            switch (cell)
            {
            case Cell::CL_X:
                imgName = "standart_blue";
                break;
            case Cell::CL_O:
                imgName = "standart_red";
                break;
            case Cell::CL_CATCH_X:
                imgName = "catch_blue";
                break;
            case Cell::CL_CATCH_O:
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
    connectionDialog->setAddressString(controller->getServerAddress(), controller->getServerPort());
    
    connectionDialog->setLogin(controller->getUserLogin());

    connectionDialog->setPassword(controller->getUserPassword());

    connectionDialog->setPref(controller->getUserPref());

    if (connectionDialog->exec() != QDialog::Accepted)
    {
        return;
    }

    controller->setConnectionInfo(connectionDialog->getAddress(), connectionDialog->getPort(), connectionDialog->getLogin(), connectionDialog->getPassword(), connectionDialog->getPref());
    
    controller->onGameStart();

    setYourLogin();
    redraw();
}

void MainWindow::redraw()
{
    if (controller->getState() == State::ST_WAITTING_FOR_THE_START)
    {
        ui->labelOpponent->clear();
        ui->labelYourLogin->clear();
    }

    if (controller->getState() == State::ST_WAITTING_FOR_THE_START)
    {
        ui->actionStart->setDisabled(false);
        ui->actionLeave->setDisabled(true);
    }
    else
    {
        ui->actionStart->setDisabled(true);
        ui->actionLeave->setDisabled(false);
    }

    if (controller->getState() == State::ST_MAKING_STEP && model->getPref() == "server")
    {
        ui->menuServer->setDisabled(false);
    }
    else
    {
        ui->menuServer->setDisabled(true);
    }

    if (!QFile::exists(DEFAULT_SAVE_FILE_1))
    {
        ui->actionDownload_1->setDisabled(true);
    }
    else
    {
        ui->actionDownload_1->setDisabled(false);
    }

    if (!QFile::exists(DEFAULT_SAVE_FILE_2))
    {
        ui->actionDownload_2->setDisabled(true);
    }
    else
    {
        ui->actionDownload_2->setDisabled(false);
    }

    if (!QFile::exists(DEFAULT_SAVE_FILE_3))
    {
        ui->actionDownload_3->setDisabled(true);
    }
    else
    {
        ui->actionDownload_3->setDisabled(false);
    }

    this->update();
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::showGameResult(GameResult result)
{
    if (result == GameResult::GR_NONE)
    {
        return;
    }

    QString messageString = result == GameResult::GR_WON ? tr("You win!") : tr("You lose!");
        
    this->update();
    QMessageBox::information(this, tr("Game result"), messageString);
}

void MainWindow::showGameError(GameErrorMessage message)
{
    QString messageString;

    switch (message)
    {
    case GameErrorMessage::GEM_WRONG_USER:
        messageString = tr("Wrong user passed!");
        break;

    case GameErrorMessage::GEM_ALREADY_CONNECTED:
        messageString = tr("You are already connected!");
        break;

    case GameErrorMessage::GEM_SERVER_ERROR:
        messageString = tr("Server error!");
        break;

    case GameErrorMessage::GEM_SERVER_CONNECTION_REFUSED:
    case GameErrorMessage::GEM_SERVER_UNAVAILABLE:
        messageString = tr("Cannot connect to the server.");
        break;

    case GameErrorMessage::GEM_SERVER_CONNECTION_TIMEOUT:
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
    QMessageBox::information(this, tr("Game Info"), tr("You have disconnected!"));

    redraw();
}

void MainWindow::on_actionSave_1_triggered()
{
    controller->onGameSave(1);
    QMessageBox::information(this, tr("Game Info"), tr("Game saved!"));

    redraw();
}

void MainWindow::on_actionSave_2_triggered()
{
    controller->onGameSave(2);
    QMessageBox::information(this, tr("Game Info"), tr("Game saved!"));

    redraw();
}

void MainWindow::on_actionSave_3_triggered()
{
    controller->onGameSave(3);
    QMessageBox::information(this, tr("Game Info"), tr("Game saved!"));

    redraw();
}

void MainWindow::on_actionDownload_1_triggered()
{
    controller->onGameDownload(1);
    getFieldImage();
    QMessageBox::information(this, tr("Game Info"), tr("Save loaded!"));

    redraw();
}

void MainWindow::on_actionDownload_2_triggered()
{
    controller->onGameDownload(2);
    getFieldImage();
    QMessageBox::information(this, tr("Game Info"), tr("Save loaded!"));

    redraw();
}

void MainWindow::on_actionDownload_3_triggered()
{
    controller->onGameDownload(3);
    getFieldImage();
    QMessageBox::information(this, tr("Game Info"), tr("Save loaded!"));

    redraw();
}