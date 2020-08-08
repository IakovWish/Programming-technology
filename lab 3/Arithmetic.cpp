#include "Arithmetic.h"
#include <iostream>
#include <fstream>

using namespace std;

Arithmetic::Arithmetic() // конструктор
{
	path = "Arithmetic_progression.txt";
	cout << "вызван конструктор арифметической" << endl;
	system("pause");
}

Arithmetic::Arithmetic(string way) // конструктор c параметрами
{
	cout << "вызван конструктор арифметической с параметрами" << endl;

	if (way == "")
	{
		path = "Arithmetic_progression.txt";
	}
	else
	{
		path = way;
	}
	system("pause");
}

Arithmetic::Arithmetic(const Arithmetic& tmp_Arithmetic)
{
	cout << "вызван конструктор копирования арифметической" << endl;
	member1 = tmp_Arithmetic.member1;
	const_diff_att = tmp_Arithmetic.const_diff_att;
	system("pause");
}

double Arithmetic::progression_amount(int value)
{
	return (2 * member1 + const_diff_att * ((double)value - 1)) / 2 * value;
}

Arithmetic::~Arithmetic()
{
	cout << "вызван деструктор арифметической" << endl;
	system("pause");
}
