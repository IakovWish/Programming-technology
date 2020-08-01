#include "Queue.h"
#include <iostream>
#include <string.h>

using namespace std;

template <typename T3, class T4>
void workWithClass1(T4* mas, T3 s)
{
	int menu1 = 1; // ���� ��� ������ � ������ ��������
	T3 value_1 = 0; // �������� ��������
	char** mas_ch = 0;
	char** new_mas_ch = 0;
	char* value_ch = 0;
	T3* new_mas; // ��������� ������
	char* value_tmp = 0;
	int quantity = 1; // ���������� ��������� �������

	/*������� ��������� �������*/
	int left;
	int right;
	int mid;

	if (strcmp(typeid(value_1).name(), "char *") != 0)
	{
		mas = new T3[1];
	}
	{
		mas_ch = new char* [1];
	}

	system("cls");
	cout << "������� ������� ������� ������� ";
	//cout << typeid(value_1).name();
	if (strcmp(typeid(value_1).name(), "char *") != 0)
	{
		cin >> value_1;
		mas[0] = value_1;
	}
	else
	{
		int i = 0;
		char ch = 0;

		cin.get(ch);
		cin.get(ch);
		value_ch = new char[1];
		while (ch != '\n')
		{
			value_tmp = new char[i];
			for (int j = 0; j < i; j++)
			{
				value_tmp[j] = value_ch[j];
			}
			value_ch = new char[i + 2];
			for (int j = 0; j < i; j++)
			{
				value_ch[j] = value_tmp[j];
			}
			value_ch[i++] = ch;
			cin.get(ch);
		}
		value_ch[i] = '\0';
		delete[] value_tmp;
		mas_ch[0] = value_ch;
	}

	while (menu1)
	{
		system("cls");
		cout << "|0| - �����" << endl;
		cout << "|1| - �������� ������� � ������" << endl;
		cout << "|2| - ����� �������" << endl;
		cout << "|3| - ������� ������" << endl;

		cin >> menu1;
		system("cls");

		switch (menu1)
		{
		case 0:
			if (strcmp(typeid(value_1).name(), "char *") != 0)
			{
				delete[] mas;
			}
			else
			{
				delete[] mas_ch;
			}
			break;

		case 1:
			cout << "������� ����� ������� ������� ";

			if (strcmp(typeid(value_1).name(), "char *") != 0)
			{
				cin >> value_1;

				new_mas = new T3[++quantity];

				for (int i = 0; i < quantity - 1; i++)
				{
					new_mas[i] = mas[i];
				}

				mas = new T3[quantity];

				for (int i = 0; i < quantity - 1; i++)
				{
					mas[i] = new_mas[i];
				}

				delete[] new_mas;
			}
			else
			{
				int i = 0;
				char ch = 0;

				cin.get(ch);
				cin.get(ch);
				value_ch = new char[1];
				while (ch != '\n')
				{
					value_tmp = new char[i];
					for (int j = 0; j < i; j++)
					{
						value_tmp[j] = value_ch[j];
					}
					value_ch = new char[i + 2];
					for (int j = 0; j < i; j++)
					{
						value_ch[j] = value_tmp[j];
					}
					value_ch[i++] = ch;
					cin.get(ch);
				}
				value_ch[i] = '\0';
				delete[] value_tmp;

				new_mas_ch = new char* [++quantity];

				for (int i = 0; i < quantity - 1; i++)
				{
					new_mas_ch[i] = mas_ch[i];
				}

				mas_ch = new char* [quantity];

				for (int i = 0; i < quantity - 1; i++)
				{
					mas_ch[i] = new_mas_ch[i];
				}

				delete[] new_mas_ch;
			}

			if (strcmp(typeid(value_1).name(), "char *") != 0)
			{
				mas[quantity - 1] = value_1;
			}
			else
			{
				mas_ch[quantity - 1] = value_ch;
			}

			cout << "������� ������:" << endl;

			if (strcmp(typeid(value_1).name(), "char *") != 0)
			{
				for (int i = 0; i < quantity; i++)
				{
					cout << mas[i] << " ";
				}
				cout << endl;
			}
			else
			{
				for (int i = 0; i < quantity; i++)
				{
					int j = 0;
					while (mas_ch[i][j] != '\0')
					{
						cout << mas_ch[i][j++];
					}
					cout << " ";
				}
				cout << endl;
			}

			system("pause");
			break;

		case 2:
			mid = 0; // ������� ������� �������
			right = quantity;
			left = 0;

			cout << "������� ������:" << endl;
			if (strcmp(typeid(value_1).name(), "char *") != 0)
			{
				for (int i = 0; i < quantity; i++)
				{
					cout << mas[i] << " ";
				}
				cout << endl;
			}
			else
			{
				for (int i = 0; i < quantity; i++)
				{
					int j = 0;
					while (mas_ch[i][j] != '\0')
					{
						cout << mas_ch[i][j++];
					}
					cout << " ";
				}
				cout << endl;
			}

			cout << "������� ������� ������� ";

			if (strcmp(typeid(value_1).name(), "char *") != 0)
			{
				cin >> value_1;
			}
			else
			{
				int i = 0;
				char ch = 0;

				cin.get(ch);
				cin.get(ch);
				value_ch = new char[1];
				while (ch != '\n')
				{
					value_tmp = new char[i];
					for (int j = 0; j < i; j++)
					{
						value_tmp[j] = value_ch[j];
					}
					value_ch = new char[i + 2];
					for (int j = 0; j < i; j++)
					{
						value_ch[j] = value_tmp[j];
					}
					value_ch[i++] = ch;
					cin.get(ch);
				}
				value_ch[i] = '\0';
				delete[] value_tmp;
			}

			while (right - left >= 0) // ���� �� ������� ���� ������
			{
				mid = (left + right) / 2; // ������ ���������� �������


				if (strcmp(typeid(value_1).name(), "char *") != 0)
				{
					if (mas[mid] == value_1) // ���� ��� ��������� ���� �����...
					{
						break; //...���������
					}
				}
				else
				{
					int flag = 0;
					int i = 0;
					do
					{
						if (mas_ch[mid][i] != value_ch[i])
						{
							flag = 1;
							break;
						}
						i++;
					} while (mas_ch[mid][i] != '\0' && value_ch[i] != '\0');

					if (flag == 0 && mas_ch[mid][i] == '\0' && value_ch[i] == '\0')
					{
						break;
					}
				}

				if (strcmp(typeid(value_1).name(), "char *") != 0)
				{
					if (mas[mid] < value_1) // ���� ������� ������� ������ ��������...
					{
						left = mid + 1; // ...������� ����� �������
					}
					else
					{
						right = mid - 1; //...����� ������
					}
				}
				else
				{
					if (strcmp(mas_ch[mid], value_ch) < 0) // ���� ������� ������� ������ ��������...
					{
						left = mid + 1; // ...������� ����� �������
					}
					else
					{
						right = mid - 1; //...����� ������
					}
				}
			}
			try
			{
				if (strcmp(typeid(value_1).name(), "char *") != 0)
				{
					if (mas[mid] == value_1)
					{
						cout << "������ �������� �� ��������� " << value_1 << " - " << mid << endl; //������� ��� ������
					}
					else
					{
						throw "������� �������� � ������� ���";
					}
				}
				else
				{
					int flag = 0;
					int i = 0;
					do
					{
						if (mas_ch[mid][i] != value_ch[i])
						{
							flag = 1;
							break;
						}
						i++;
					} while (mas_ch[mid][i] != '\0' && value_ch[i] != '\0');

					if (flag == 0 && mas_ch[mid][i] == '\0' && value_ch[i] == '\0')
					{
						cout << "������ �������� �������� - " << mid << endl; //������� ��� ������
					}
					else
					{
						throw "������� �������� � ������� ���";
					}
				}
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			system("pause");
			break;

		case 3:
			cout << "������� ������:" << endl;
			if (strcmp(typeid(value_1).name(), "char *") != 0)
			{
				for (int i = 0; i < quantity; i++)
				{
					cout << mas[i] << " ";
				}
				cout << endl;
			}
			else
			{
				for (int i = 0; i < quantity; i++)
				{
					int j = 0;
					while (mas_ch[i][j] != '\0')
					{
						cout << mas_ch[i][j++];
					}
					cout << " ";
				}
				cout << endl;
			}
			system("pause");
			break;

		default:
			cout << "������������ ����";
			system("pause");
			break;
		}
	}
}

template <typename T1, class T2>
void workWithClass2(T2*& queue, T1 x)
{
	queue = new T2[1];
	int menu2 = 1; // ����� ������������ � ���� ������� �������
	int current_number = 0; // ����� ������� �������
	int total = 1; // ����� ���������� �������� ��� ������ ��������� ���������

	while (menu2)
	{
		T2* queue_new = 0; // ��������� ������ ��������
		int choise; // ����� ��������� ������������� �������

		system("cls");
		cout << "������������ ������� � " << current_number + 1 << endl;
		cout << "����� �������� " << total << endl;
		cout << "|0| - �����" << endl;
		cout << "|1| - ���������� �������� � ������� �������" << endl;
		cout << "|2| - ���������� �������� �� ������� �������" << endl;
		cout << "|3| - ����� ������� ������� �� �����" << endl;
		cout << "|4| - ���������� �������� � ����� ������� � ������������ �� ���" << endl;
		cout << "|5| - ����� ���� ��������" << endl;
		cout << "|6| - ����� ������ �������" << endl;
		cout << "|7| - ������� ��� �������" << endl;
		cout << "|8| - ������� �� ����� ������� ������" << endl;
		cin >> menu2;
		system("cls");

		switch (menu2)
		{
		case 0:
			delete[] queue;
			break;

		case 1:
			cin >> queue[current_number];
			cout << "������� ��������\n������� ������� � " << current_number + 1 << ":" << endl;
			cout << queue[current_number];
			system("pause");
			break;

		case 2:
			try
			{
				!queue[current_number];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
				system("pause");
				break;
			}

			queue[current_number].pop();
			cout << "������� ������� � " << current_number + 1 << ":" << endl;

			try
			{
				!queue[current_number];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
				system("pause");
				break;
			}
			cout << queue[current_number];
			system("pause");
			break;

		case 3:
			cout << "������� ������� � " << current_number + 1 << ":" << endl;
			try
			{
				!queue[current_number];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
				system("pause");
				break;
			}
			cout << queue[current_number];
			system("pause");
			break;

		case 4:
			try
			{
				for (current_number = 0; current_number < total; current_number++)
				{
					cout << "��� ������� " << current_number + 1 << " ";
					!queue[current_number];
					system("cls");
				}

				current_number = total; // ������������� �� �������, ������� ������ ��������
				queue_new = new Queue<T1>[++total]; // ������� ��������� ������, ������� �� 1 ������ ������ ���������� ��������

				for (int i = 0; i < total - 1; i++) // �������� ��� ������� ����� ��������� � ����� ������
				{
					queue_new[i].copyQueue(queue[i]);
				}

				cin >> queue_new[total - 1]; // ��������� ������� � ����� �������
				cout << "������� �������� � ����� �������" << endl;

				delete[] queue;

				queue = new Queue<T1>[total]; // �������� ������ � ������ ������� ��� ����� ���������� ��������

				for (int i = 0; i < total; i++) // �������� ��� ������� �� ���������� ������� � ������
				{
					queue[i].copyQueue(queue_new[i]);
				}

				delete[] queue_new; // ��������� ������ �� �����

				cout << "������������ �� ����� ������� ���������" << endl;
				cout << "������� ������� � " << current_number + 1 << ":" << endl;
				try
				{
					!queue[current_number];
				}
				catch (const char* ex)
				{
					cout << ex << endl;
					system("pause");
					break;
				}
				cout << queue[current_number];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
				cout << "������ �� ����������� �� ������ ������� � ������ ���������� �����" << endl;
			}
			system("pause");
			break;

		case 5:
			for (int i = 0; i < total; i++) // ������� ��� ������� �� �����
			{
				cout << "������� � " << i + 1 << " ������� ��:" << endl;
				try
				{
					!queue[i];
					cout << queue[i];
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
			}
			system("pause");
			break;

		case 6:
			if (total == 1)
			{
				cout << "���������� ������ ���� �������" << endl;
				break;
			}
			cout << "������� ����� ������� �� 1 �� " << total << " �� ������� ������� �������������:\n(����� " << current_number + 1 << ", ��� ��� ��� ������ ������������)" << endl;

			for (int i = 0; i < total; i++) // ������� ��� ������� �� �����
			{
				cout << "������� � " << i + 1 << " ������� ��:" << endl;
				try
				{
					!queue[i];
					cout << queue[i];
				}
				catch (const char* ex)
				{
					cout << ex << endl;
				}
			}

			cin >> choise;
			system("cls");
			choise--; // ���������� ������������

			if ((choise < 0) || (choise == current_number) || (choise >= total))
			{
				cout << "������������ ��������. ������������ �� ���������" << endl;
			}
			else
			{
				current_number = choise;
				cout << "������������ ���������" << endl;
				cout << "������� � " << current_number + 1 << " ������� ��:" << endl;
				try
				{
					!queue[current_number];
				}
				catch (const char* ex)
				{
					cout << ex << endl;
					system("pause");
					break;
				}
				cout << queue[current_number];
			}
			system("pause");
			break;

		case 7:
			try
			{
				!queue[current_number];

				cout << "������� ����� ������� c ������� ������� ������� �� 1 �� " << total << ":\n(����� " << current_number + 1 << ", ��� ��� ��� ������ ������������)" << endl;

				for (int i = 0; i < total; i++) // ������� ��� ������� �� �����
				{
					cout << "������� � " << i + 1 << " ������� ��:" << endl;
					try
					{
						!queue[i];
						cout << queue[i];
					}
					catch (const char* ex)
					{
						cout << ex << endl;
					}
				}

				cin >> choise;
				choise--;

				if ((choise < 0) || (choise == current_number) || (choise >= total))
				{
					cout << "������������ ��������. �������� �� �����������" << endl;
					system("pause");
					break;
				}
				queue[current_number] + queue[choise];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			system("pause");
			break;

		case 8:
			try
			{
				!queue[current_number];

				cout << "������� ����� ������� c ������� ������� ������� �� 1 �� " << total << ":\n(����� " << current_number + 1 << ", ��� ��� ��� ������ ������������)" << endl;

				for (int i = 0; i < total; i++) // ������� ��� ������� �� �����
				{
					cout << "������� � " << i + 1 << " ������� ��:" << endl;
					try
					{
						!queue[i];
						cout << queue[i];
					}
					catch (const char* ex)
					{
						cout << ex << endl;
					}
				}

				cin >> choise;
				choise--;

				if ((choise < 0) || (choise == current_number) || (choise >= total))
				{
					cout << "������������ ��������. ��������� �� �����������" << endl;
					system("pause");
					break;
				}
				queue[current_number] - queue[choise];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			system("pause");
			break;

		default:
			cout << "������������ ����" << endl;
			system("pause");
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	system("chcp 1251");
	system("cls");

	int menu_1 = 1; // ����� ���� ������

	int* mas1 = 0;
	int s1 = 0;
	float* mas2 = 0;
	float s2 = 0;
	double* mas3 = 0;
	double s3 = 0;
	char* mas4 = 0;
	char s4 = 0;
	char** mas5 = 0;
	char* s5 = 0;

	while (menu_1)
	{
		system("cls");
		cout << "������� �1 �������� �������-������ ��������� ������" << endl;
		cout << "�������� ��� ������ ��� �������" << endl;
		cout << "|0| - ������� � ������� �2" << endl;
		cout << "|1| - int" << endl;
		cout << "|2| - float" << endl;
		cout << "|3| - double" << endl;
		cout << "|4| - char" << endl;
		cout << "|5| - char*" << endl;
		cin >> menu_1;

		switch (menu_1)
		{
		case 0:
			break;

		case 1:
			workWithClass1(mas1, s1);
			break;

		case 2:
			workWithClass1(mas2, s2);
			break;

		case 3:
			workWithClass1(mas3, s3);
			break;

		case 4:
			workWithClass1(mas4, s4);
			break;

		case 5:
			workWithClass1(mas5, s5);
			break;

		default:
			cout << "������������ ����" << endl;
			system("pause");
			break;
		}
	}

	int menu_2 = 1; // �����

	Queue<int>* queue1 = 0;
	int x1 = 0;
	Queue<float>* queue2 = 0;
	float x2 = 0;
	Queue<double>* queue3 = 0;
	double x3 = 0;
	Queue<char>* queue4 = 0;
	char x4 = 0;

	while (menu_2)
	{
		system("cls");
		cout << "������� �2 ������� ����������������� �������" << endl;
		cout << "�������� ��� ������ ��� �������" << endl;
		cout << "|0| - ����� �� ���������" << endl;
		cout << "|1| - int" << endl;
		cout << "|2| - float" << endl;
		cout << "|3| - double" << endl;
		cout << "|4| - char" << endl;
		cin >> menu_2;

		switch (menu_2)
		{
		case 0:
			break;

		case 1:
			workWithClass2(queue1, x1);
			break;

		case 2:
			workWithClass2(queue2, x2);
			break;

		case 3:
			workWithClass2(queue3, x3);
			break;

		case 4:
			workWithClass2(queue4, x4);
			break;

		default:
			cout << "������������ ����" << endl;
			system("pause");
			break;
		}
	}
	return 1;
}