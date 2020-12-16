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

void Field::setField(QString oldField, int& steps)
{
    setFieldPrivate(oldField, field_, steps);
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

void Field::setFieldPrivate(QString oldField, Field::Cells& cells, int& steps)
{
    steps = 0;
    for (int i = 0; i != 100; i++)
    {
        if (oldField[i] == "0")
        {
            cells[i] = Field::Cell::CLEAR;
        }
        else if (oldField[i] == "1")
        {
            cells[i] = Field::Cell::X;
            steps++;
        }
        else if (oldField[i] == "2")
        {
            cells[i] = Field::Cell::O;
        }
        else if (oldField[i] == "3")
        {
            cells[i] = Field::Cell::CATCH_X;
            steps++;
        }
        else if (oldField[i] == "4")
        {
            cells[i] = Field::Cell::CATCH_O;
        }
    }

    if ((steps + 1) % 3 == 0)
    {
        steps = 3; // last step
    }
    else if ((steps + 2) % 3 == 0)
    {
        steps = 2; // second step
    }
    else if (steps % 3 == 0)
    {
        steps = 1; // first step
    }
}

quint32 Field::getFieldLength() const
{
    return fieldLength_;
}

quint32 Field::getFieldSize() const
{
    return fieldLength_ * fieldLength_;
}

bool Field::makeStep(int x, int y)
{
    Cell cell = getCell(x, y);

    if (cell == Cell::O)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Field::isNewStepPossible(int& possible)
{
    for (int i = 0; i < 10 && possible < 3; i++)
    {
        for (int j = 0; j < 10 && possible < 3; j++)
        {
            Cell massiv[10][10];

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    massiv[i][j] = Cell::ZERO;
                }
            }

            Cell cell1 = getCell(i, j);

            if (cell1 != Cell::CATCH_X && cell1 != Cell::CATCH_O && cell1 != Cell::X && active(i, j, massiv))
            {
                possible++;
                Cell cell2 = cell1 == Cell::O ? Cell::CATCH_X : Cell::X;
                setCell(i, j, cell2);
                if (isNewStepPossible(possible))
                {
                    setCell(i, j, cell1);
                    return true;
                }
                setCell(i, j, cell1);
            }
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

    if ((x == 0 && y == 0 && cell != Cell::X && cell != Cell::O) || (x == 10 - 1 && y == 10 - 1 && cell != Cell::X && cell != Cell::O))
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