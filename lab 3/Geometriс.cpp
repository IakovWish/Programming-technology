#include "Geometric.h"
#include <iostream>
#include <fstream>

using namespace std;

Geometric::Geometric() // �����������
{
	path = "Geometric_progression.txt";
	cout << "������ ����������� ��������������" << endl;
	system("pause");
}

Geometric::Geometric(string way) // ����������� c �����������
{
	cout << "������ ����������� �������������� � �����������" << endl;

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

Geometric::Geometric(const Geometric& tmp_Geometri�)
{
	cout << "������ ����������� ����������� ��������������" << endl;
	member1 = tmp_Geometri�.member1;
	const_diff_att = tmp_Geometri�.const_diff_att;
	system("pause");
}

double Geometric::progression_amount(int value)
{
	return (member1 * (1 - pow(const_diff_att, value))) / (1 - const_diff_att);
}

Geometric::~Geometric()
{
	cout << "������ ���������� ��������������" << endl;
	system("pause");
}