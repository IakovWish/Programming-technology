#include <QDebug>
#include <QString>
#include <qiterator.h>
#include "Field.h"

Field::Field()
{
    fieldLength_ = 10;
    field_.fill(Cell::CLEAR, getFieldSize() );
}

Field::Cell Field::getCell( int x, int y ) const
{
    return getCellPrivate( x, y, field_ );
}

void Field::setCell( int x, int y, Cell cell )
{
    setCellPrivate( x, y, cell, field_ );
}

Field::Cell Field::getCellPrivate(int x, int y, const Field::Cells& cells) const
{
    int n = y * fieldLength_ + x;

    if (x < 0 || y < 0 || x >= (qint32)getFieldLength() || y >= (qint32)getFieldLength())
    {
        return Cell::CLEAR;
    }

    if (n < 0 || (quint32)n > getFieldSize())
    {
        return Cell::CLEAR;
    }

    return cells[n];
}

void Field::setCellPrivate(int x, int y, Cell cell, Field::Cells& cells) const
{
    int n = y * fieldLength_ + x;

    if (x < 0 || y < 0 || x >= (qint32)getFieldLength() || y >= (qint32)getFieldLength())
    {
        return;
    }

    if (n < 0 || (quint32)n > getFieldSize())
    {
        return;
    }

    cells[n] = cell;
}

quint32 Field::getFieldLength() const
{
    return fieldLength_;
}

quint32 Field::getFieldSize() const
{
    return fieldLength_ * fieldLength_;
}

bool Field::makeStep(int x, int y, Moves& newMoves)
{
    newMoves.clear();
    Cell cell = getCell(x, y);
    newMoves.push_back(QPoint(x, y));
    if (cell == Cell::CLEAR || cell == Cell::CATCH_X || cell == Cell::CATCH_O || cell == Cell::X)
    {
        return false;
    }
    else if (cell == Cell::O)
    {
        return true;
    }
}

//void Field::guess(int x, int y, int& possible)
//{
//    Cell MASS[10][10];
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            MASS[i][j] = Cell::ZERO;
//        }
//    }
//
//    Cell cell1 = getCell(x, y);
//
//    if (getCell(x, y) == Cell::CLEAR || getCell(x, y) == Cell::O)
//    {
//        Cell cell2 = cell1 == Cell::O ? Cell::CATCH_X : Cell::X;
//
//        if (active(x, y, MASS) && ++possible < 3)
//        {
//            setCell(x, y, cell2);
//
//            if (x < 10 - 1 && active(x + 1, y, MASS))
//            {
//                guess(x + 1, y, possible);
//            }
//
//            if (x > 0 && active(x - 1, y, MASS))
//            {
//                guess(x - 1, y, possible);
//            }
//
//            if (y < 10 - 1 && active(x, y + 1, MASS))
//            {
//                guess(x, y + 1, possible);
//            }
//
//            if (y > 0 && active(x, y - 1, MASS))
//            {
//                guess(x, y - 1, possible);
//            }
//
//            if (x < 10 - 1 && y < 10 - 1 && active(x + 1, y + 1, MASS))
//            {
//                guess(x + 1, y + 1, possible);
//            }
//
//            if (x < 10 - 1 && y > 0 && active(x + 1, y - 1, MASS))
//            {
//                guess(x + 1, y - 1, possible);
//            }
//
//            if (x > 0 && y < 10 - 1 && active(x - 1, y + 1, MASS))
//            {
//                guess(x - 1, y + 1, possible);
//            }
//
//            if (x > 0 && y > 0 && active(x - 1, y - 1, MASS))
//            {
//                guess(x - 1, y - 1, possible);
//            }
//            
//            setCell(x, y, cell1);
//        }
//    }
//    else if ((active(x, y, MASS) && cell1 == Cell::CATCH_X) || cell1 == Cell::X)
//    {
//        if ((x < 10 - 1 && active(x + 1, y, MASS) /*|| getCell(x + 1, y) == Cell::X*/) && (getCell(x + 1, y) == Cell::CLEAR || getCell(x + 1, y) == Cell::O))
//        {
//            if (++possible >= 3)
//            {
//                return;
//            }
//            guess(x + 1, y, possible);
//        }
//
//        if ((x > 0 && active(x - 1, y, MASS) /*|| getCell(x - 1, y) == Cell::X*/) && (getCell(x - 1, y) == Cell::CLEAR || getCell(x - 1, y) == Cell::O))
//        {
//            if (++possible >= 3)
//            {
//                return;
//            }
//            guess(x - 1, y, possible);
//        }
//
//        if ((y < 10 - 1 && active(x, y + 1, MASS) /*|| getCell(x, y + 1) == Cell::X*/) && (getCell(x, y + 1) == Cell::CLEAR || getCell(x, y + 1) == Cell::O))
//        {
//            if (++possible >= 3)
//            {
//                return;
//            }
//            guess(x, y + 1, possible);
//        }
//
//        if ((y > 0 && active(x, y - 1, MASS) /*|| getCell(x, y - 1) == Cell::X*/) && (getCell(x, y - 1) == Cell::CLEAR || getCell(x, y - 1) == Cell::O))
//        {
//            if (++possible >= 3)
//            {
//                return;
//            }
//            guess(x, y - 1, possible);
//        }
//
//        if (x < 10 - 1 && y < 10 - 1 && (active(x + 1, y + 1, MASS) /*|| getCell(x + 1, y + 1) == Cell::X*/) && (getCell(x + 1, y + 1) == Cell::CLEAR || getCell(x + 1, y + 1) == Cell::O))
//        {
//            if (++possible >= 3)
//            {
//                return;
//            }
//            guess(x + 1, y + 1, possible);
//        }
//
//        if ((x < 10 - 1 && y > 0 && active(x + 1, y - 1, MASS) /*|| getCell(x + 1, y - 1) == Cell::X*/) && (getCell(x + 1, y - 1) == Cell::CLEAR || getCell(x + 1, y - 1) == Cell::O))
//        {
//            if (++possible >= 3)
//            {
//                return;
//            }
//            guess(x + 1, y - 1, possible);
//        }
//
//        if ((x > 0 && y < 10 - 1 && active(x - 1, y + 1, MASS) /*|| getCell(x - 1, y + 1) == Cell::X*/) && (getCell(x - 1, y + 1) == Cell::CLEAR || getCell(x - 1, y + 1) == Cell::O))
//        {
//            if (++possible >= 3)
//            {
//                return;
//            }
//            guess(x - 1, y + 1, possible);
//        }
//
//        if ((x > 0 && y > 0 && active(x - 1, y - 1, MASS) /*|| getCell(x - 1, y - 1) == Cell::X*/) && (getCell(x - 1, y - 1) == Cell::CLEAR || getCell(x - 1, y - 1) == Cell::O))
//        {
//            if (++possible >= 3)
//            {
//                return;
//            }
//            guess(x - 1, y - 1, possible);
//        }
//    }
//}

bool Field::isNewStepPossible()
{
    int possible = 0;

    for (int i = 0; i < 10 && possible < 3; i++)
    {
        for (int j = 0; j < 10 && possible < 3; j++)
        {
            //guess(i, j, possible);
        }
    }

    if (possible >= 3 || getCell(0, 0) == Cell::CLEAR || getCell(10 - 1, 10 - 1) == Cell::CLEAR)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Field::isPossible(int x, int y)
{
    if (x < 0 || y < 0 || x >= 10 || y >= 10)
    {
        return false;
    }

    Cell cell = getCell(x, y);

    if (cell == Cell::CATCH_X || cell == Cell::CATCH_O || cell == Cell::X)
    {
        return false;
    }

    if (x == 0 && y == 0 && cell != Cell::X && cell != Cell::O || x == 10 - 1 && y == 10 - 1 && cell != Cell::X && cell != Cell::O)
    {
        return true;
    }

    Cell massiv[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            massiv[i][j] = Cell::ZERO;
        }
    }

    return active(x, y, massiv);
}

bool Field::active(int x, int y, Cell(&MASS)[10][10])
{
    MASS[x][y] = Cell::CLEAR;

    if (y != 0 && MASS[x][y - 1] != Cell::CLEAR) // если мы находимся не на самой вехней строке, cмотрим элемент сверху
    {
        if (getCell(x, y - 1) == Cell::X)
        {
            return true;
        }
        else if (getCell(x, y - 1) == Cell::CATCH_X)
        {
            if (MASS[x][y - 1] != Cell::CLEAR && active(x, y - 1, MASS) == true)
            {
                return true;
            }
        }
        MASS[x][y - 1] = Cell::CLEAR;
    }

    if (x != 10 - 1 && MASS[x + 1][y] != Cell::CLEAR) // если мы находимся не на самой правой строке, cмотрим элемент справа
    {
        if (getCell(x + 1, y) == Cell::X)
        {
            return true;
        }
        else if (getCell(x + 1, y) == Cell::CATCH_X)
        {
            if (MASS[x + 1][y] != Cell::CLEAR && active(x + 1, y, MASS) == true)
            {
                return true;
            }
        }
        MASS[x + 1][y] = Cell::CLEAR;
    }

    if (y != 10 - 1 && MASS[x][y + 1] != Cell::CLEAR) // если мы находимся не на самой нижней строке, cмотрим элемент снизу
    {
        if (getCell(x, y + 1) == Cell::X)
        {
            return true;
        }
        else if (MASS[x][y + 1] != Cell::CLEAR && getCell(x, y + 1) == Cell::CATCH_X)
        {
            if (active(x, y + 1, MASS) == true)
            {
                return true;
            }
        }
        MASS[x][y + 1] = Cell::CLEAR;
    }

    if (x != 0 && MASS[x - 1][y] != Cell::CLEAR) // если мы находимся не на самой левой строке, cмотрим элемент слева
    {
        if (getCell(x - 1, y) == Cell::X)
        {
            return true;
        }
        else if (getCell(x - 1, y) == Cell::CATCH_X)
        {
            if (MASS[x - 1][y] != Cell::CLEAR && active(x - 1, y, MASS) == true)
            {
                return true;
            }
        }
        MASS[x - 1][y] = Cell::CLEAR;
    }

    if (x != 0 && y != 0 && MASS[x - 1][y - 1] != Cell::CLEAR)
    {
        if (getCell(x - 1, y - 1) == Cell::X)
        {
            return true;
        }
        else if (getCell(x - 1, y - 1) == Cell::CATCH_X)
        {
            if (MASS[x - 1][y - 1] != Cell::CLEAR && active(x - 1, y - 1, MASS) == true)
            {
                return true;
            }
        }
        MASS[x - 1][y - 1] = Cell::CLEAR;
    }

    if (x != 10 - 1 && y != 10 - 1 && MASS[x + 1][y + 1] != Cell::CLEAR)
    {
        if (getCell(x + 1, y + 1) == Cell::X)
        {
            return true;
        }
        else if (getCell(x + 1, y + 1) == Cell::CATCH_X)
        {
            if (MASS[x + 1][y + 1] != Cell::CLEAR && active(x + 1, y + 1, MASS) == true)
            {
                return true;
            }
        }
        MASS[x + 1][y + 1] = Cell::CLEAR;
    }

    if (x != 0 && y != 10 - 1 && MASS[x - 1][y + 1] != Cell::CLEAR)
    {
        if (getCell(x - 1, y + 1) == Cell::X)
        {
            return true;
        }
        else if (getCell(x - 1, y + 1) == Cell::CATCH_X)
        {
            if (MASS[x - 1][y + 1] != Cell::CLEAR && active(x - 1, y + 1, MASS) == true)
            {
                return true;
            }
        }
        MASS[x - 1][y + 1] = Cell::CLEAR;
    }

    if (x != 10 - 1 && y != 0 && MASS[x + 1][y - 1] != Cell::CLEAR)
    {
        if (getCell(x + 1, y - 1) == Cell::X)
        {
            return true;
        }
        else if (getCell(x + 1, y - 1) == Cell::CATCH_X)
        {
            if (MASS[x + 1][y - 1] != Cell::CLEAR && active(x + 1, y - 1, MASS) == true)
            {
                return true;
            }
        }
        MASS[x + 1][y - 1] = Cell::CLEAR;
    }

    return false;
}