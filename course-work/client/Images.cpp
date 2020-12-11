#include "Images.h"

Images pictures = Images();

Images::Images():
    isLoaded_( false )
{
}

void Images::load()
{
    if (isLoaded_)
    {
        return;
    }

    images.insert("catch_red", QImage(":/images/catch_red.png"));
    images.insert("catch_blue", QImage(":/images/catch_blue.png"));
    images.insert("standart_blue", QImage(":/images/standart_blue.png"));
    images.insert("standart_red", QImage(":/images/standart_red.png"));
    images.insert("new_red", QImage(":/images/new_red.png"));
    images.insert("new_blue", QImage(":/images/new_blue.png"));
    images.insert("new_catch_red", QImage(":/images/new_catch_red.png"));
    images.insert("new_catch_blue", QImage(":/images/new_catch_blue.png"));
    isLoaded_ = true;
}

QImage& Images::get( const QString& imgName )
{
    QMap<QString, QImage>::iterator i = images.find( imgName );

    if( i == images.end() )
        throw 1;

    return i.value();
}

bool Images::isLoaded()
{
    return isLoaded_;
}
