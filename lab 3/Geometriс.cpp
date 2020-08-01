#include "Geometric.h"
#include <iostream>
#include <fstream>

using namespace std;

Geometric::Geometric() // конструктор
{
	path = "Geometric_progression.txt";
	cout << "вызван конструктор геометрической" << endl;
	system("pause");
}

Geometric::Geometric(string way) // конструктор c параметрами
{
	cout << "вызван конструктор геометрической с параметрами" << endl;

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

Geometric::Geometric(const Geometric& tmp_Geometriс)
{
	cout << "вызван конструктор копирования геометрической" << endl;
	member1 = tmp_Geometriс.member1;
	const_diff_att = tmp_Geometriс.const_diff_att;
	system("pause");
}

double Geometric::progression_amount(int value)
{
	return (member1 * (1 - pow(const_diff_att, value))) / (1 - const_diff_att);
}

Geometric::~Geometric()
{
	cout << "вызван деструктор геометрической" << endl;
	system("pause");
}