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
        CLEAR = 0,
        X,
        O,
        NEW_X,
        NEW_O,
        CATCH_X,
        CATCH_O,
        CATCH_NEW_X,
        CATCH_NEW_O,
        ZERO
    };

    typedef QVector<Cell> Cells;
    typedef QStack<QPoint> Moves;

public:
    Field();
    Cell getCell( int x, int y ) const;
    void setCell( int x, int y, Cell cell );
    void setField(QString oldField, int& steps);
    quint32 getFieldLength() const;
    quint32 getFieldSize() const;
    bool makeStep(int x, int y);
    bool isNewStepPossible(int& possible);
    bool isPossible(int x, int y);
    bool active(int x, int y, Cell(&MASS)[10][10]);

private:
    Cell getCellPrivate( int x, int y, const Cells& cells ) const;
    void setCellPrivate( int x, int y, Cell cell, Cells& cells ) const;
    void setFieldPrivate(QString oldField, Field::Cells& cells, int& step);

private:
    int fieldLength_;
    Cells field_;
};