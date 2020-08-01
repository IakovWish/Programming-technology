#include "Arithmetic.h"
#include "Geometric.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int option = 1;

	Arithmetic ap;
	Geometric gp;

	Arithmetic ap_c(ap); // ��� �������� ������ ������������ �����������
	Geometric gp_c(gp); // ��� �������� ������ ������������ �����������

	while (option)
	{
		system("cls");
		double sum = 0;
		int value = 0;
		cout << "�������� ����� ���� � ������� ���" << endl;
		cout << "|0| - ����� �� ���������" << endl;
		cout << "|1| - ����� �������������� ������������������" << endl;
		cout << "|2| - ����� �������������� ������������������" << endl;
		cout << "|3| - ����� �� ����� ����������� �������������� �������������������" << endl;
		cout << "|4| - ����� �� ����� ����������� �������������� �������������������" << endl;
		cin >> option;

		switch (option)
		{
		case 0:
			break;

		case 1:
			cout << "������� ���������� ��������� ����������" << endl;
			cin >> value;
			ap.reader();
			sum = ap.progression_amount(value);
			cout << "����� ���������� = " << sum << endl;
			ap.input(sum, value);
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "������� ���������� ��������� ����������" << endl;
			cin >> value;
			gp.reader();
			sum = gp.progression_amount(value);
			cout << "����� ���������� = " << sum << endl;
			gp.input(sum, value);
			system("pause");
			system("cls");
			break;

		case 3:
			ap.output();
			system("pause");
			system("cls");
			break;

		case 4:
			gp.output();
			system("pause");
			system("cls");
			break;

		default:
			cout << "������������ ����" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}