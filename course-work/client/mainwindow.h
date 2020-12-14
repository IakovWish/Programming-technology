#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QString>
#include <QTime>
#include <QVBoxLayout>
#include "Images.h"
#include "Model.h"
#include "Controller.h"
#include "Defines.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow( QWidget* parent = 0 );
    ~MainWindow();

protected:
    void paintEvent( QPaintEvent* event );
    void mousePressEvent( QMouseEvent* ev );
    void closeEvent( QCloseEvent* event );

private slots:
    void redraw();
    void showGameResult(GameResult result);
    void showGameError(GameErrorMessage message);
    void changeGameOpponent(const QString& name);
    void on_actionStart_triggered();
    void on_actionQuit_triggered();
    void on_actionLeave_triggered();
    void on_actionSave_1_triggered();
    void on_actionSave_2_triggered();
    void on_actionSave_3_triggered();
    void on_actionDownload_1_triggered();
    void on_actionDownload_2_triggered();
    void on_actionDownload_3_triggered();

private:
    void setStatus( const QString& status );

private:
    QImage getFieldImage();

private:
    Ui::MainWindow* ui;
    State state;
    Model* model;
    Controller* controller;
};

#endif // MAINWINDOW_H
