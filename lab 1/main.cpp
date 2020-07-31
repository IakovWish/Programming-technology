#include "Son.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

template <class tmpl>
void workWithClass(tmpl* queue) // ������ ������ ��� ������ c ������� ������������ � �������� �������, ������� ��������� �� �����
{
    int choise; // ����� ��������� ������������� �������
    int number = 0; // ����� �������������� �������
    int count = 1; // ���������� �������� � �������� �������� ������������
    int value; // ��������� ��������
    int Menu; // ��������� ����� ����
    int flag = 1; // ������� ������ ���������

    do
    {
        system("cls");
        cout << "������������ ������� � " << number << endl;
        cout << "'1' - ���������� �������� �������" << endl;
        cout << "'2' - ���������� �������� �� �������" << endl;
        cout << "'3' - ����� ������� �� �����" << endl;
        cout << "'4' - ���������� ������������ ��������" << endl;
        cout << "'5' - �������� ����� �������" << endl;
        cout << "'6' - ������� ������������ ������� � ������ � ����� ���������� �� �����" << endl;
        cout << "'7' - ����� ������ �������" << endl;
        cout << "'8' - �����" << endl;
        cin >> Menu;
        system("cls");

        switch (Menu)
        {
        case 1:
            cout << "������� ��������: ";
            cin >> value;
            system("cls");
            queue[number].push(value); // �������� �������� � �������
            cout << "������� " << value << " ��������" << endl;
            cout << "������� ������� � " << number << " ������� ��:" << endl;
            queue[number].out(); // ����� �� ����� ��������� �������
            system("pause");
            break;

        case 2:
            if (!queue[number].check()) break; // �������� �������
            cout << "������� �� ����������:" << endl;
            queue[number].out(); // ����� �� ����� ��������� �������
            value = queue[number].pop(); // ���������� �� ��������� �������
            cout << "�������� �������:" << value << endl;
            cout << "������� ����� ����������:" << endl;
            queue[number].out(); // ����� �� ����� ��������� �������
            system("pause");
            break;

        case 3:
            if (!queue[number].check()) break;
            cout << "������� � " << number << " ������� ��:" << endl;
            queue[number].out(); // ����� �� ����� ��������� �������
            system("pause");
            break;

        case 4:
            if (!queue[number].check()) break;
            cout << "������� �������:" << endl;
            queue[number].out(); // ����� �� ����� ��������� �������
            cout << "����������� �������: " << queue[number].min_unit_finder() << endl; // ������� 4
            system("pause");
            break;

        case 5:
            if (!queue[number].check()) break;
            queue[count].copy(queue[number]); // ����������� ��������� �������
            cout << "������� �����������. ����� �������: " << count++ << endl;
            system("pause");
            break;

        case 6:
            if (count == 1)
            {
                cout << "���������� ������ ���� �������" << endl;
                system("pause");
                break;
            }

            cout << "� ����� �������� ����� ����������� �������? (0 - " << count - 1 << ") :  ";
            cin >> choise;
            system("cls");

            if ((choise < 0) || (choise == number) || (choise >= count))
            {
                cout << "������������ ��������. ����������� �� �����������" << endl;
                system("pause");
                break;
            }

            queue[count].merger(queue[number], queue[choise]);
            cout << "����������� �����������. ����� ������� ����������: " << count << endl;
            count++;
            system("pause");
            break;

        case 7:
            if (count == 1)
            {
                cout << "���������� ������ ���� �������" << endl;
                system("pause");
                break;
            }

            cout << "�� ���������� � ������� � " << number << endl;
            cout << "������� ����� ������� (�� 0 �� " << count - 1 << ", ����� " << number << ", ��� ��� ��� ������ ������������), �� ������� ������� �������������: ";
            cin >> choise;
            system("cls");
            if ((choise < 0) || (choise == number) || (choise >= count))
            {
                cout << "������������ ��������. ������������ �� ���������" << endl;
            }
            else
            {
                number = choise;
                cout << "������� �������:" << endl;
                queue[number].out(); // ����� �� ����� ��������� �������
            }
            system("pause");
            break;

        case 8:
            flag = 0;
        }
    } while (flag == 1);
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int Number_Q; // ���������� ��������
    int Type_son; // ����� ���� ������������

    cout << "������� ���������� ��������" << endl;
    cin >> Number_Q;
    system("cls");

    sub1* Object1 = NULL;
    sub2* Object2 = NULL;
    sub3* Object3 = NULL;

    cout << "�������� ��� ������������" << endl;
    cout << "'1' - Public" << endl;
    cout << "'2' - Protected" << endl;
    cout << "'3' - Private" << endl;
    cin >> Type_son;
    system("cls");

    switch (Type_son)
    {
    case 1:
        Object1 = new sub1[Number_Q];
        workWithClass(Object1);
        delete[] Object1;
        break;

    case 2:
        Object2 = new sub2[Number_Q];
        workWithClass(Object2);
        delete[] Object2;
        break;

    case 3:
        Object3 = new sub3[Number_Q];
        workWithClass(Object3);
        delete[] Object3;
        break;

    default:
        cout << "������������ ����";
        break;
    }

    return 0;
}