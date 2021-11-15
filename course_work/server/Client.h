#pragma once

#include <QtNetwork/QTcpSocket>
#include <ctime>
#include "Field.h"

class Client
{
public:
    typedef QMap<int, Client>::iterator ClientIterator;

    enum class ClientStatus
    {
        INITIALIZATION = -1,
        CONNECTED = 0,
        AUTHORIZED,
        READY,
        WAITING_STEP,
        MAKING_STEP,
        DISCONNECTED
    };

    enum class ClientStatusGame
    {
        INITIALIZATION = -1,
        ONLINE = 0,
        ONLINE_PREF,
        OFFLINE
    };

    explicit Client();
    ~Client();

    void send( const QString& cmd );

    QTcpSocket* socket;
    ClientStatus status = ClientStatus::INITIALIZATION;
    ClientStatusGame status_game = ClientStatusGame::INITIALIZATION;
    ClientIterator playingWith;
    QString login;
    int step;
    QString prefLogin = (QString::null);

    void setField(QString oldField);
    Field* field();
    void setSeen();
    size_t lastSeen();

private:
    Field* field_;
    size_t lastSeen_ = 0;
};

typedef QMap<int, Client> Clients;
typedef Clients::iterator ClientsIterator;