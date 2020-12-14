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
        CONNECTED = 0,
        AUTHORIZED,
        READY,
        READY_TO_PLAY_WITH_SERVER,
        AUTHORIZED_TO_PLAY_WITH_SERVER,
        WAITING_STEP,
        MAKING_STEP,
        DISCONNECTED
    };

    explicit Client();
    ~Client();

    void send( const QString& cmd );

    QTcpSocket* socket;
    ClientStatus status;
    ClientIterator playingWith;
    QString login;
    int step;

    void setField(QString oldField);
    Field* field();
    void setSeen();
    size_t lastSeen();

private:
    Field* field_;
    size_t lastSeen_;
};

typedef QMap<int, Client> Clients;
typedef Clients::iterator ClientsIterator;