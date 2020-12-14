#pragma once
#include <QString>
#include <QObject>
#include "Field.h"

enum class State
{
    ST_WAITTING_FOR_THE_START,
    ST_WAITING_STEP,
    ST_MAKING_STEP,
    MAKING_SAVE
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
    void setPref(const QString& str);
    QString getLogin() const;
    QString getPassword() const;
    QString getPref() const;

    Cell getCell(int x, int y) const;
    void setCell(int x, int y, Cell cell);
    void setField(QString oldField) const;
    QString getField() const;
    void clearField();

private:
    Field* field;

    State state;
    QString login, pass, pref;
};