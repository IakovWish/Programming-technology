#include "Client.h"

Client::Client():
    field_( NULL )
{
    step = 0;
}

Client::~Client()
{
    if (field_)
    {
        delete field_;
    }
}

void Client::send( const QString& cmd )
{
    QTextStream clientStream( socket );
    clientStream << cmd;
    clientStream << flush;
}

void Client::setField()
{
    field_ = new Field();
}

Field* Client::field()
{
    return field_;
}

void Client::setSeen()
{
    lastSeen_=time(NULL);
}

size_t Client::lastSeen()
{
    return time(NULL)-lastSeen_;
}