#include <QDebug>
#include <QString>
#include <qiterator.h>
#include "Field.h"

Field::Field()
{
    field_.fill(Cell::CI_CLEAR, getFieldSize() );
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
        return Cell::CI_CLEAR;
    }

    if (n < 0 || (quint32)n > getFieldSize())
    {
        return Cell::CI_CLEAR;
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
    if (cell == Cell::CI_CLEAR || cell == Cell::CI_CATCH_X || cell == Cell::CI_CATCH_O || cell == Cell::CI_X)
    {
        return false;
    }
    else if (cell == Cell::CI_O)
    {
        return true;
    }
}