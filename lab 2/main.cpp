#include "Queue.h"
#include "coordinate.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

void show(Queue& queue_1, Queue& queue_2);

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// Queue queue = 0; // невозможно, так как мы запретили неявное преобразование типа этого аргумента в тип класса
	Queue queue_1;
	Queue queue_2(0);

	int option = 1;

	while (option)
	{
		cout << "Задание 1 - унарные операции" << endl;
		cout << "|0| - Переход к бинарным операциям" << endl;
		cout << "|1| - Добавление элемента очереди" << endl;
		cout << "|2| - Извлечение элемента из очереди" << endl;
		cout << "|3| - Увеличение всех элементов очереди на 1" << endl;
		cout << "|4| - Уменьшение всех элементов очереди на 1" << endl;
		cin >> option;

		switch (option)
		{
		case 0:
			break;

		case 1:
			queue_1 = queue_2++;
			show(queue_1, queue_2);
			system("pause");
			system("cls");
			break;

		case 2:
			if (!queue_2)
			{
				queue_1 = queue_2--;
				show(queue_1, queue_2);
			}
			system("pause");
			system("cls");
			break;

		case 3:
			if (!queue_2)
			{
				queue_1 = ++queue_2;
				show(queue_1, queue_2);
			}
			system("pause");
			system("cls");
			break;

		case 4:
			if (!queue_2)
			{
				queue_1 = --queue_2;
				show(queue_1, queue_2);
			}
			system("pause");
			system("cls");
			break;

		default:
			cout << "некорректный ввод";
			system("pause");
			system("cls");
			break;
		}
	}

	system("cls");

	option = 1;
	// coordinate xyz = 0; // невозможно, так как мы запретили неявное преобразование типа этого аргумента в тип класса
	coordinate xyz_1(0);
	coordinate xyz_2(xyz_1);

	int number = 0;

	while (option)
	{
		cout << "Задание 2 - бинарные операции" << endl;
		cout << "координата 1 " << xyz_1 << endl;
		cout << "координата 2 " << xyz_2 << endl;
		cout << "число " << number << endl;
		cout << "|0|  - Выход" << endl;
		cout << "|1|  - Ввод координаты 1" << endl;
		cout << "|2|  - Вывод координаты 1" << endl;
		cout << "|3|  - Ввод координаты 2" << endl;
		cout << "|4|  - Вывод координаты 2" << endl;
		cout << "|5|  - Прибавить к координате 1 число" << endl;
		cout << "|6|  - Вычисть из координаты 1 число" << endl;
		cout << "|7|  - Прибавить к координате 2 число" << endl;
		cout << "|8|  - Вычисть из координаты 2 число" << endl;
		cout << "|9|  - Прибавить к координате 1 координату 2" << endl;
		cout << "|10| - Прибавить к координате 2 координату 1" << endl;
		cout << "|11| - Вычисть из координаты 1 координату 2" << endl;
		cout << "|12| - Вычисть из координаты 2 координату 1" << endl;
		cout << "|13| - Изменить число" << endl;
		cout << "|14| - Вывод числа" << endl;
		cout << "|15| - Изменить число на рандомное" << endl;
		cout << "|16| - поменять значение координат местами" << endl;
		cout << "|17| - !=" << endl;
		cout << "|18| - ==" << endl;

		cin >> option;

		switch (option)
		{
		case 0: // выход
			break;

		case 1:
			cin >> xyz_1; // ввод координаты 1
			system("cls");
			break;

		case 2:
			cout << xyz_1 << endl; // вывод координаты 1
			system("pause");
			system("cls");
			break;

		case 3:
			cin >> xyz_2; // ввод координаты 2
			system("cls");
			break;

		case 4:
			cout << xyz_2 << endl; // вывод координаты 2
			system("pause");
			system("cls");
			break;

		case 5:
			cout << "координата 1 = координата 1 + число = " << xyz_1 << " + " << number << " = "; // сложение числа с координатой 1
			xyz_1 + number;
			cout << xyz_1 << endl;
			system("pause");
			system("cls");
			break;

		case 6:
			cout << "координата 1 = координата 1 - число = " << xyz_1 << " - " << number << " = "; // вычитание числа из координаты 1
			xyz_1 - number;
			cout << xyz_1 << endl;
			system("pause");
			system("cls");
			break;

		case 7:
			cout << "координата 2 = координата 2 + число = " << xyz_2 << " + " << number << " = "; // сложение числа с координатой 2
			xyz_2 + number;
			cout << xyz_2 << endl;
			system("pause");
			system("cls");
			break;

		case 8:
			cout << "координата 2 = координата 2 - число = " << xyz_2 << " - " << number << " = "; // вычитание числа из координаты 2
			xyz_2 - number;
			cout << xyz_2 << endl;
			system("pause");
			system("cls");
			break;

		case 9:
			cout << "координата 1 = координата 1 + координата 2 = " << xyz_1 << " + " << xyz_2 << " = "; // Сложение координаты 1 и 2
			xyz_1 + xyz_2;
			cout << xyz_1 << endl;
			system("pause");
			system("cls");
			break;

		case 10:
			cout << "координата 2 = координата 2 + координата 1 = " << xyz_2 << " + " << xyz_1 << " = "; // Сложение координаты 2 и 1
			xyz_2 + xyz_1;
			cout << xyz_2 << endl;
			system("pause");
			system("cls");
			break;

		case 11:
			cout << "координата 1 = координата 1 - координата 2 = " << xyz_1 << " - " << xyz_2 << " = "; // Вычитание из координаты 1 координату 2
			xyz_1 - xyz_2;
			cout << xyz_1 << endl;
			system("pause");
			system("cls");
			break;

		case 12:
			cout << "координата 2 = координата 2 - координата 1 = " << xyz_2 << " - " << xyz_1 << " = "; // Вычитание из координаты 2 координату 1
			xyz_2 - xyz_1;
			cout << xyz_2 << endl;
			system("pause");
			system("cls");
			break;

		case 13:
			cout << "Введите число" << endl; // ввод числа
			cin >> number;
			system("cls");
			break;

		case 14:
			cout << "Текущее число " << number << endl; // вывод числа
			system("pause");
			system("cls");
			break;

		case 15:
			number = 0 + rand() % 11;
			system("cls");
			break;

		case 16:
			swop(xyz_1, xyz_2);
			system("cls");
			break;

		case 17:
			xyz_2 != xyz_1;
			system("pause");
			system("cls");
			break;

		case 18:
			xyz_2 == xyz_1;
			system("pause");
			system("cls");
			break;

		default:
			cout << "некорректный ввод\n";
			system("pause");
			system("cls");
			break;
		}
	}
}

void show(Queue& queue_1, Queue& queue_2)
{
	cout << "Очередь 1" << endl;
	if (!queue_1)
	{
		queue_1.out();
	}
	cout << "Очередь 2" << endl;
	if (!queue_2)
	{
		queue_2.out();
	}
}
