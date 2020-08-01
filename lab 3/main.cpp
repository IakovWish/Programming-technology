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

	Arithmetic ap_c(ap); // для проверки работы конструктора копирования
	Geometric gp_c(gp); // для проверки работы конструктора копирования

	while (option)
	{
		system("cls");
		double sum = 0;
		int value = 0;
		cout << "Выберите пункт меню и введите его" << endl;
		cout << "|0| - Выход из программы" << endl;
		cout << "|1| - Сумма арифметической последовательности" << endl;
		cout << "|2| - Сумма геометрической последовательности" << endl;
		cout << "|3| - Вывод на экран результатов арифметических последовательностей" << endl;
		cout << "|4| - Вывод на экран результатов геометрических последовательностей" << endl;
		cin >> option;

		switch (option)
		{
		case 0:
			break;

		case 1:
			cout << "Введите количество элементов прогрессии" << endl;
			cin >> value;
			ap.reader();
			sum = ap.progression_amount(value);
			cout << "Сумма прогрессии = " << sum << endl;
			ap.input(sum, value);
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "Введите количество элементов прогрессии" << endl;
			cin >> value;
			gp.reader();
			sum = gp.progression_amount(value);
			cout << "Сумма прогрессии = " << sum << endl;
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
			cout << "Некорректный ввод" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}