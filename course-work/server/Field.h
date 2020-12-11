#pragma once

#include <QVector>
#include <QStack>
#include <QPoint>
#include "Constants.h"

class Field
{
public:
    enum class Cell
    {
        CI_CLEAR = 0,
        CI_X,
        CI_O,
        CI_NEW_X,
        CI_NEW_O,
        CI_CATCH_X,
        CI_CATCH_O,
        CI_CATCH_NEW_X,
        CI_CATCH_NEW_O
    };

    typedef QVector<Cell> Cells;
    typedef QStack<QPoint> Moves;

public:
    Field();
    Cell getCell( int x, int y ) const;
    void setCell( int x, int y, Cell cell );
    quint32 getFieldLength() const;
    quint32 getFieldSize() const;
    bool makeStep(int x, int y, Moves& newMoves);

private:
    Cell getCellPrivate( int x, int y, const Cells& cells ) const;
    void setCellPrivate( int x, int y, Cell cell, Cells& cells ) const;

private:
    int fieldLength_;
    Cells field_;
};