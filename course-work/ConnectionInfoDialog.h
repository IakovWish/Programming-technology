#pragma once
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QLabel>

class ConnectionInfoDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConnectionInfoDialog( QWidget* parent = 0 );
    ~ConnectionInfoDialog();

    void setAddressString( const QString& address, quint16 port );
    void setAddressString( const QHostAddress& address, quint16 port );
    void setLogin( const QString& login );
    void setPassword( const QString& password);
    void setPref(const QString& pref);
    QString getAddress() const;
    QString getLogin() const;
    QString getPassword() const;
    QString getPref() const;
    quint16 getPort();

public slots:
    void accept();
    void ServerGame();

protected:
    bool eventFilter(QObject* object, QEvent* event);

private:
    QLineEdit* addressTextBox;
    QLineEdit* loginTextBox;
    QLineEdit* passTextBox;
    QLineEdit* prefTextBox;

    QCheckBox* serverCheckBox;

    QLabel* addrLabel;
    QLabel* loginLabel;
    QLabel* passLabel;
    QLabel* prefLabel;
    QLabel* serverLabel;

    QPushButton* cancelButton;
    QPushButton* applyButton;

    QHBoxLayout* addrLayout;
    QHBoxLayout* loginLayout;
    QHBoxLayout* passLayout;
    QHBoxLayout* prefLayout;
    QHBoxLayout* serverLayout;
    QHBoxLayout* buttonLayout;
    QVBoxLayout* verticalLayout;

    QGridLayout* layout;

    QString address;
    QString login;
    QString pass;
    QString pref;
    quint16 port;
    bool server_check;
};