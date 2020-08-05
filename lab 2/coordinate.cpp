#include "coordinate.h"
#include <iostream>
using namespace std;

coordinate::coordinate() :x(0), y(0), z(0) // конструктор
{
	// привет
}

coordinate::coordinate(int X, int Y, int Z) // конструктор с параметрами
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

coordinate::coordinate(const coordinate& tmp_xyz) // конструктор копирования
{
	this->x = tmp_xyz.x;
	this->y = tmp_xyz.y;
	this->z = tmp_xyz.z;
}

coordinate::~coordinate() // деструктор
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

istream& operator>>(istream& in, coordinate& xyz) // перегруженный ввод
{
	int option = 0;
	cout << "|0|  - Задать координаты вручную" << endl;
	cout << "|1|  - Задать координаты рандомно" << endl;
	cin >> option;


	switch (option)
	{
	case 0:
		cout << "Введите x  "; in >> xyz.x;
		cout << "Введите y  "; in >> xyz.y;
		cout << "Введите z  "; in >> xyz.z;
		break;

	case 1:
		xyz.random();
		break;

	default:
		cout << "некорректный ввод\n";
		system("pause");
		system("cls");
		break;
	}

	return in;
}

ostream& operator<<(ostream& os, coordinate& xyz) // перегруженный вывод
{
	os << "{" << xyz.x << ", " << xyz.y << ", " << xyz.z << "}";
	return os;
}

void coordinate::operator + (int number) // перегруженный оператор + как метод для ЧИСЛА И ЭКЗЕМПЛЯРА
{
	x += number;
	y += number;
	z += number;
}

void coordinate::operator + (coordinate& xyz) // перегруженный оператор + как метод для ДВУХ ЭКЗЕМПЛЯРОВ
{
	x += xyz.x;
	y += xyz.y;
	z += xyz.z;
}

void operator - (coordinate& xyz, int number) // перегруженный оператор - как дружественная функция для ЧИСЛА И ЭКЗЕМПЛЯРА
{
	xyz.x -= number;
	xyz.y -= number;
	xyz.z -= number;
}

void operator - (coordinate& xyz_1, coordinate& xyz_2) // перегруженный оператор - как дружественная функция для ДВУХ ЭКЗЕМПЛЯРОВ
{
	xyz_1.x -= xyz_2.x;
	xyz_1.y -= xyz_2.y;
	xyz_1.z -= xyz_2.z;
}

void coordinate::operator==(const coordinate xyz)
{
	cout << "x " << (x == xyz.x ? "true" : "false") << endl;
	cout << "y " << (y == xyz.y ? "true" : "false") << endl;
	cout << "z " << (z == xyz.z ? "true" : "false") << endl;
}

void operator != (coordinate& xyz_1, coordinate& xyz_2)
{
	cout << "x " << (xyz_1.x != xyz_2.x ? "true" : "false") << endl;
	cout << "y " << (xyz_1.y != xyz_2.y ? "true" : "false") << endl;
	cout << "z " << (xyz_1.z != xyz_2.z ? "true" : "false") << endl;
}

void swop(coordinate& xyz_1, coordinate& xyz_2)
{
	coordinate tmp_xyz;

	tmp_xyz.x = xyz_1.x;
	tmp_xyz.y = xyz_1.y;
	tmp_xyz.z = xyz_1.z;

	xyz_1.x = xyz_2.x;
	xyz_1.y = xyz_2.y;
	xyz_1.z = xyz_2.z;

	xyz_2.x = tmp_xyz.x;
	xyz_2.y = tmp_xyz.y;
	xyz_2.z = tmp_xyz.z;
}

coordinate coordinate::random(int X, int Y, int Z)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
	return *this;
}
