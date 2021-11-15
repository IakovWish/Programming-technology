#include "Field.h"

Field::Field()
{
    clear();
}

Field::~Field()
{

}

Cell Field::getCell( int x, int y )
{
    int n = y * 10 + x;

    if (x < 0 || y < 0 || x >= 10 || y >= 10)
    {
        return Cell::CL_CLEAR;
    }

    if (n >= 0 && n < field.size())
    {
        return field[n];
    }

    //qDebug() << "ERROR: no such cell";
    return Cell::CL_CLEAR;
}

void Field::setCell( int x, int y, Cell cell )
{
    int n = y * 10 + x;

    if(x >= 0 && y >= 0 && x < 10 && y < 10 && n >= 0 && n < field.size())
    {
        field[n] = cell;
        return;
    }
    //qDebug() << "ERROR: no such cell (" << x << "x" << y << ")";
}

void Field::setField(QString oldField)
{
    for (int i = 0; i != 100; i++)
    {
        if (oldField[i] == "0")
        {
            field[i] = Cell::CL_CLEAR;
        }
        else if (oldField[i] == "1")
        {
            field[i] = Cell::CL_X;
        }
        else if (oldField[i] == "2")
        {
            field[i] = Cell::CL_O;
        }
        else if (oldField[i] == "3")
        {
            field[i] = Cell::CL_CATCH_X;
        }
        else if (oldField[i] == "4")
        {
            field[i] = Cell::CL_CATCH_O;
        }
    }
}

QString Field::getField()
{
    QString result;

    for (QVector<Cell>::iterator i = field.begin(); i != field.end(); i++)
    {
        if (*i == Cell::CL_CLEAR)
        {
            result += "0";
        }
        else if (*i == Cell::CL_X)
        {
            result += "1";
        }
        else if (*i == Cell::CL_O)
        {
            result += "2";
        }
        else if (*i == Cell::CL_CATCH_X)
        {
            result += "3";
        }
        else if (*i == Cell::CL_CATCH_O)
        {
            result += "4";
        }
    }

    return result;
}

void Field::clear()
{
    field.fill(Cell::CL_CLEAR, 100 );
}