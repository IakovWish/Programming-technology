#include "Client.h"

Client::Client():
    field_( NULL )
{
    step = 1;
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

void Client::setField(QString oldField)
{
    field_ = new Field();
    field_->setField(oldField, step);
}

Field* Client::field()
{
    return field_;
}

void Client::setSeen()
{
    lastSeen_ = time(NULL);
}

size_t Client::lastSeen()
{
    return time(NULL)-lastSeen_;
}