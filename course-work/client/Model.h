#pragma once
#include <QString>
#include <QObject>
#include "Field.h"

enum State
{
    ST_WAITTING_FOR_THE_START,
    ST_WAITING_STEP,
    ST_MAKING_STEP
};

class Model: public QObject
{
    Q_OBJECT
public:
    Model();
    ~Model();
    State getState() const;
    void setState( State );
    void setLogin(const QString& str);
    void setPassword(const QString& str);
    QString getLogin() const;
    QString getPassword() const;
    bool isPossible(int x, int y);

    Cell getCell(int x, int y) const;
    void setCell(int x, int y, Cell cell);
    QString getField() const;
    void clearField();

private:
    Field* field;

    State state;
    QString login, pass;
};