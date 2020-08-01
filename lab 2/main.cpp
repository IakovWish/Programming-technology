#include "Queue.h"
#include "coordinate.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void show(Queue& queue_1, Queue& queue_2);

int main()
{
	setlocale(LC_ALL, "Rus");

	// Queue queue = 0; // ����������, ��� ��� �� ��������� ������� �������������� ���� ����� ��������� � ��� ������
	Queue queue_1;
	Queue queue_2(0);

	int option = 1;

	while (option)
	{
		cout << "������� 1 - ������� ��������" << endl;
		cout << "|0| - ������� � �������� ���������" << endl;
		cout << "|1| - ���������� �������� �������" << endl;
		cout << "|2| - ���������� �������� �� �������" << endl;
		cout << "|3| - ���������� ���� ��������� ������� �� 1" << endl;
		cout << "|4| - ���������� ���� ��������� ������� �� 1" << endl;
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
			cout << "������������ ����";
			system("pause");
			system("cls");
			break;
		}
	}

	system("cls");

	option = 1;
	// coordinate xyz = 0; // ����������, ��� ��� �� ��������� ������� �������������� ���� ����� ��������� � ��� ������
	coordinate xyz_1(0);
	coordinate xyz_2(xyz_1);

	int number = 0;

	while (option)
	{
		cout << "������� 2 - �������� ��������" << endl;
		cout << "���������� 1 " << xyz_1 << endl;
		cout << "���������� 2 " << xyz_2 << endl;
		cout << "����� " << number << endl;
		cout << "|0|  - �����" << endl;
		cout << "|1|  - ���� ���������� 1" << endl;
		cout << "|2|  - ����� ���������� 1" << endl;
		cout << "|3|  - ���� ���������� 2" << endl;
		cout << "|4|  - ����� ���������� 2" << endl;
		cout << "|5|  - ��������� � ���������� 1 �����" << endl;
		cout << "|6|  - ������� �� ���������� 1 �����" << endl;
		cout << "|7|  - ��������� � ���������� 2 �����" << endl;
		cout << "|8|  - ������� �� ���������� 2 �����" << endl;
		cout << "|9|  - ��������� � ���������� 1 ���������� 2" << endl;
		cout << "|10| - ��������� � ���������� 2 ���������� 1" << endl;
		cout << "|11| - ������� �� ���������� 1 ���������� 2" << endl;
		cout << "|12| - ������� �� ���������� 2 ���������� 1" << endl;
		cout << "|13| - �������� �����" << endl;
		cout << "|14| - ����� �����" << endl;
		cout << "|15| - �������� ����� �� ���������" << endl;
		cout << "|16| - �������� �������� ��������� �������" << endl;
		cout << "|17| - !=" << endl;
		cout << "|18| - ==" << endl;

		cin >> option;

		switch (option)
		{
		case 0: // �����
			break;

		case 1:
			cin >> xyz_1; // ���� ���������� 1
			system("cls");
			break;

		case 2:
			cout << xyz_1 << endl; // ����� ���������� 1
			system("pause");
			system("cls");
			break;

		case 3:
			cin >> xyz_2; // ���� ���������� 2
			system("cls");
			break;

		case 4:
			cout << xyz_2 << endl; // ����� ���������� 2
			system("pause");
			system("cls");
			break;

		case 5:
			cout << "���������� 1 = ���������� 1 + ����� = " << xyz_1 << " + " << number << " = "; // �������� ����� � ����������� 1
			xyz_1 + number;
			cout << xyz_1 << endl;
			system("pause");
			system("cls");
			break;

		case 6:
			cout << "���������� 1 = ���������� 1 - ����� = " << xyz_1 << " - " << number << " = "; // ��������� ����� �� ���������� 1
			xyz_1 - number;
			cout << xyz_1 << endl;
			system("pause");
			system("cls");
			break;

		case 7:
			cout << "���������� 2 = ���������� 2 + ����� = " << xyz_2 << " + " << number << " = "; // �������� ����� � ����������� 2
			xyz_2 + number;
			cout << xyz_2 << endl;
			system("pause");
			system("cls");
			break;

		case 8:
			cout << "���������� 2 = ���������� 2 - ����� = " << xyz_2 << " - " << number << " = "; // ��������� ����� �� ���������� 2
			xyz_2 - number;
			cout << xyz_2 << endl;
			system("pause");
			system("cls");
			break;

		case 9:
			cout << "���������� 1 = ���������� 1 + ���������� 2 = " << xyz_1 << " + " << xyz_2 << " = "; // �������� ���������� 1 � 2
			xyz_1 + xyz_2;
			cout << xyz_1 << endl;
			system("pause");
			system("cls");
			break;

		case 10:
			cout << "���������� 2 = ���������� 2 + ���������� 1 = " << xyz_2 << " + " << xyz_1 << " = "; // �������� ���������� 2 � 1
			xyz_2 + xyz_1;
			cout << xyz_2 << endl;
			system("pause");
			system("cls");
			break;

		case 11:
			cout << "���������� 1 = ���������� 1 - ���������� 2 = " << xyz_1 << " - " << xyz_2 << " = "; // ��������� �� ���������� 1 ���������� 2
			xyz_1 - xyz_2;
			cout << xyz_1 << endl;
			system("pause");
			system("cls");
			break;

		case 12:
			cout << "���������� 2 = ���������� 2 - ���������� 1 = " << xyz_2 << " - " << xyz_1 << " = "; // ��������� �� ���������� 2 ���������� 1
			xyz_2 - xyz_1;
			cout << xyz_2 << endl;
			system("pause");
			system("cls");
			break;

		case 13:
			cout << "������� �����" << endl; // ���� �����
			cin >> number;
			system("cls");
			break;

		case 14:
			cout << "������� ����� " << number << endl; // ����� �����
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
			cout << "������������ ����\n";
			system("pause");
			system("cls");
			break;
		}
	}
}

void show(Queue& queue_1, Queue& queue_2)
{
	cout << "������� 1" << endl;
	if (!queue_1)
	{
		queue_1.out();
	}
	cout << "������� 2" << endl;
	if (!queue_2)
	{
		queue_2.out();
	}
}