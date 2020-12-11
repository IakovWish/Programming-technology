#pragma once
#include <QVector>
#include <QDebug>
#include <QString>

enum Cell
{
    CL_CLEAR = 0,
    CL_X,
    CL_O,
    CL_CATCH_X,
    CL_CATCH_O,
    CL_NEW_X,
    CL_NEW_O,
    CL_NEW_CATCH_X,
    CL_NEW_CATCH_O,
    CL_ZERO
};

class Field
{
public:
    Field();
    ~Field();
    Cell getCell( int x, int y );
    void setCell( int x, int y, Cell cell );
    QString getField();
    void clear();
    bool active(int x, int y, Cell (&MASS)[10][10]);

private:
    QVector<Cell> field;
};