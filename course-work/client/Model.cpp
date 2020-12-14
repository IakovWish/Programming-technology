#include "Model.h"

Model::Model()
{
    field = new Field;
    state = State::ST_WAITTING_FOR_THE_START;
}

Model::~Model()
{
    delete field;
}

Cell Model::getCell(int x, int y) const
{
    return field->getCell(x, y);
}

void Model::setCell(int x, int y, Cell cell)
{
    field->setCell(x, y, cell);
}

QString Model::getField() const
{
    return field->getField();
}

void Model::setField(QString oldField) const
{
    return field->setField(oldField);
}

State Model::getState() const
{
    return state;
}

void Model::setState( State st )
{
    state = st;
}

void Model::setLogin( const QString& str )
{
    login = str;
}

void Model::setPassword( const QString& str )
{
    pass = str;
}

void Model::setPref(const QString& str)
{
    pref = str;
}

QString Model::getLogin() const
{
    return login;
}

QString Model::getPassword() const
{
    return pass;
}

QString Model::getPref() const
{
    return pref;
}

void Model::clearField()
{
    field->clear();
}