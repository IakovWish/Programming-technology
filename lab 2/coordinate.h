#pragma once
#include <iostream>

using namespace std;

class coordinate
{
	friend void operator - (coordinate& xyz, int number);
	friend void operator - (coordinate& xyz_1, coordinate& xyz_2);

	friend istream& operator>>(istream& in, coordinate& xyz);
	friend ostream& operator<<(ostream& os, coordinate& xyz);

	friend void operator != (coordinate& xyz_1, coordinate& xyz_2);

	friend void swop(coordinate& xyz_1, coordinate& xyz_2);

private:
	int x, y, z;

protected:

public:
	coordinate(); // конструктор
	explicit coordinate(int X, int Y = 0, int Z = 0); // конструктор с параметрами
	coordinate(const coordinate& tmp_xyz); // конструктор копирования

	~coordinate(); // деструктор

	void operator + (int number);
	void operator + (coordinate& xyz);

	void operator == (const coordinate xyz);

	coordinate random(int X = 0 + rand() % 11, int Y = 0 + rand() % 11, int Z = 0 + rand() % 11); //  методы/функции с аргументами по умолчанию
};
