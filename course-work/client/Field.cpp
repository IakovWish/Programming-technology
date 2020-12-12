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

QString Field::getField()
{
    QString result;

    for (QVector<Cell>::iterator i = field.begin(); i != field.end(); i++)
    {
        if (*i == Cell::CL_CLEAR)
        {
            result += "0";
        }
        else
        {
            result += "1";
        }
    }

    return result;
}

void Field::clear()
{
    field.fill(Cell::CL_CLEAR, 100 );
}

//bool Field::active(int x, int y, Cell (&MASS)[10][10])
//{
//    MASS[x][y] = Cell::CL_CLEAR;
//
//    if (y != 0 && MASS[x][y - 1] != Cell::CL_CLEAR) // если мы находимся не на самой вехней строке, cмотрим элемент сверху
//    {
//        if (getCell(x, y - 1) == Cell::CL_X)
//        {
//            return true;
//        }
//        else if (getCell(x, y - 1) == Cell::CL_CATCH_X)
//        {
//            if (MASS[x][y - 1] != Cell::CL_CLEAR && active(x, y - 1, MASS) == true)
//            {
//                return true;
//            }
//        }
//        MASS[x][y - 1] = Cell::CL_CLEAR;
//    }
//
//    if (x != 10 - 1 && MASS[x + 1][y] != Cell::CL_CLEAR) // если мы находимся не на самой правой строке, cмотрим элемент справа
//    {
//        if (getCell(x + 1, y) == Cell::CL_X)
//        {
//            return true;
//        }
//        else if (getCell(x + 1, y) == Cell::CL_CATCH_X)
//        {
//            if (MASS[x + 1][y] != Cell::CL_CLEAR && active(x + 1, y, MASS) == true)
//            {
//                return true;
//            }
//        }
//        MASS[x + 1][y] = Cell::CL_CLEAR;
//    }
//
//    if (y != 10 - 1 && MASS[x][y + 1] != Cell::CL_CLEAR) // если мы находимся не на самой нижней строке, cмотрим элемент снизу
//    {
//        if (getCell(x, y + 1) == Cell::CL_X)
//        {
//            return true;
//        }
//        else if (MASS[x][y + 1] != Cell::CL_CLEAR && getCell(x, y + 1) == Cell::CL_CATCH_X)
//        {
//            if (active(x, y + 1, MASS) == true)
//            {
//                return true;
//            }
//        }
//        MASS[x][y + 1] = Cell::CL_CLEAR;
//    }
//
//    if (x != 0 && MASS[x - 1][y] != Cell::CL_CLEAR) // если мы находимся не на самой левой строке, cмотрим элемент слева
//    {
//        if (getCell(x - 1, y) == Cell::CL_X)
//        {
//            return true;
//        }
//        else if (getCell(x - 1, y) == Cell::CL_CATCH_X)
//        {
//            if (MASS[x - 1][y] != Cell::CL_CLEAR && active(x - 1, y, MASS) == true)
//            {
//                return true;
//            }
//        }
//        MASS[x - 1][y] = Cell::CL_CLEAR;
//    }
//
//    if (x != 0 && y != 0 && MASS[x - 1][y - 1] != Cell::CL_CLEAR)
//    {
//        if (getCell(x - 1, y - 1) == Cell::CL_X)
//        {
//            return true;
//        }
//        else if (getCell(x - 1, y - 1) == Cell::CL_CATCH_X)
//        {
//            if (MASS[x - 1][y - 1] != Cell::CL_CLEAR && active(x - 1, y - 1, MASS) == true)
//            {
//                return true;
//            }
//        }
//        MASS[x - 1][y - 1] = Cell::CL_CLEAR;
//    }
//
//    if (x != 10 - 1 && y != 10 - 1 && MASS[x + 1][y + 1] != Cell::CL_CLEAR)
//    {
//        if (getCell(x + 1, y + 1) == Cell::CL_X)
//        {
//            return true;
//        }
//        else if (getCell(x + 1, y + 1) == Cell::CL_CATCH_X)
//        {
//            if (MASS[x + 1][y + 1] != Cell::CL_CLEAR && active(x + 1, y + 1, MASS) == true)
//            {
//                return true;
//            }
//        }
//        MASS[x + 1][y + 1] = Cell::CL_CLEAR;
//    }
//
//    if (x != 0 && y != 10 - 1 && MASS[x - 1][y + 1] != Cell::CL_CLEAR)
//    {
//        if (getCell(x - 1, y + 1) == Cell::CL_X)
//        {
//            return true;
//        }
//        else if (getCell(x - 1, y + 1) == Cell::CL_CATCH_X)
//        {
//            if (MASS[x - 1][y + 1] != Cell::CL_CLEAR && active(x - 1, y + 1, MASS) == true)
//            {
//                return true;
//            }
//        }
//        MASS[x - 1][y + 1] = Cell::CL_CLEAR;
//    }
//
//    if (x != 10 - 1 && y != 0 && MASS[x + 1][y - 1] != Cell::CL_CLEAR)
//    {
//        if (getCell(x + 1, y - 1) == Cell::CL_X)
//        {
//            return true;
//        }
//        else if (getCell(x + 1, y - 1) == Cell::CL_CATCH_X)
//        {
//            if (MASS[x + 1][y - 1] != Cell::CL_CLEAR && active(x + 1, y - 1, MASS) == true)
//            {
//                return true;
//            }
//        }
//        MASS[x + 1][y - 1] = Cell::CL_CLEAR;
//    }
//
//    return false;
//}