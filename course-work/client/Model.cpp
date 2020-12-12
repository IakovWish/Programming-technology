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

QString Model::getLogin() const
{
    return login;
}

QString Model::getPassword() const
{
    return pass;
}

void Model::clearField()
{
    field->clear();
}

//bool Model::isPossible(int x, int y)
//{
//    if (x < 0 || y < 0 || x >= 10 || y >= 10)
//    {
//        return false;
//    }
//
//    Cell cell = field->getCell(x, y);
//
//    if (cell == Cell::CL_CATCH_X || cell == Cell::CL_CATCH_O || cell == Cell::CL_X)
//    {
//        return false;
//    }
//
//    if (x == 0 && y == 0 && cell != Cell::CL_X && cell != Cell::CL_O || x == 10 - 1 && y == 10 - 1 && cell != Cell::CL_X && cell != Cell::CL_O)
//    {
//        return true;
//    }
//
//    Cell massiv[10][10];
//
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            massiv[i][j] = Cell::CL_ZERO;
//        }
//    }
//
//    //bool act = false;
//
//    //if (field->active(x, y, massiv))
//    //{
//    //    act = true;
//    //}
//
//    return field->active(x, y, massiv);
//
//    //return x > 0 && field->getCell(x - 1, y) == Cell::CL_X || field->getCell(x - 1, y) == Cell::CL_CATCH_X && act == true
//    //    || x < 10 - 1 && field->getCell(x + 1, y) == Cell::CL_X || field->getCell(x + 1, y) == Cell::CL_CATCH_X && act == true
//    //    || y > 0 && field->getCell(x, y - 1) == Cell::CL_X || field->getCell(x, y - 1) == Cell::CL_CATCH_X && act == true
//    //    || y < 10 - 1 && field->getCell(x, y + 1) == Cell::CL_X || field->getCell(x, y + 1) == Cell::CL_CATCH_X && act == true
//    //    || x > 0 && y > 0 && field->getCell(x - 1, y - 1) == Cell::CL_X || field->getCell(x - 1, y - 1) == Cell::CL_CATCH_X && act == true
//    //    || x < 10 - 1 && y < 10 - 1 && field->getCell(x + 1, y + 1) == Cell::CL_X || field->getCell(x + 1, y + 1) == Cell::CL_CATCH_X && act == true
//    //    || x > 0 && y < 10 - 1 && field->getCell(x - 1, y + 1) == Cell::CL_X || field->getCell(x - 1, y + 1) == Cell::CL_CATCH_X && act == true
//    //    || x < 10 - 1 && y > 0 && field->getCell(x + 1, y - 1) == Cell::CL_X || field->getCell(x + 1, y - 1) == Cell::CL_CATCH_X && act == true;
//}