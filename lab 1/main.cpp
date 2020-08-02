#include "Son.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

template <class tmpl>
void workWithClass(tmpl* queue) // шаблон класса для работы c разными наследниками в основной функции, передаём указатель на класс
{
    int choise; // номер выбранной пользователем очереди
    int number = 0; // Номер обрабатываемой очереди
    int count = 1; // Количество очередей с которыми работает пользователь
    int value; // введенное значение
    int Menu; // выбранный пункт меню
    int flag = 1; // признак работы программы

    do
    {
        system("cls");
        cout << "Используется очередь № " << number << endl;
        cout << "'1' - Добавление элемента очереди" << endl;
        cout << "'2' - Извлечение элемента из очереди" << endl;
        cout << "'3' - Вывод очереди на экран" << endl;
        cout << "'4' - Нахождение минимального элемента" << endl;
        cout << "'5' - Создание копии очереди" << endl;
        cout << "'6' - Слияние оригинальной очереди с копией и вывод результата на экран" << endl;
        cout << "'7' - Выбор другой очереди" << endl;
        cout << "'8' - Выход" << endl;
        cin >> Menu;
        system("cls");

        switch (Menu)
        {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            system("cls");
            queue[number].push(value); // внесение значения в очередь
            cout << "Элемент " << value << " добавлен" << endl;
            cout << "Текущая очередь № " << number << " состоит из:" << endl;
            queue[number].out(); // вывод на экран выбранной очереди
            system("pause");
            break;

        case 2:
            if (!queue[number].check()) break; // проверка очереди
            cout << "Очередь до извлечения:" << endl;
            queue[number].out(); // вывод на экран выбранной очереди
            value = queue[number].pop(); // извлечение из выбранной очереди
            cout << "Извлечён элемент:" << value << endl;
            cout << "Очередь после извлечения:" << endl;
            queue[number].out(); // вывод на экран выбранной очереди
            system("pause");
            break;

        case 3:
            if (!queue[number].check()) break;
            cout << "Очередь № " << number << " состоит из:" << endl;
            queue[number].out(); // вывод на экран выбранной очереди
            system("pause");
            break;

        case 4:
            if (!queue[number].check()) break;
            cout << "Текущая очередь:" << endl;
            queue[number].out(); // вывод на экран выбранной очереди
            cout << "Минимальный элемент: " << queue[number].min_unit_finder() << endl; // Задание 4
            system("pause");
            break;

        case 5:
            if (!queue[number].check()) break;
            queue[count].copy(queue[number]); // копирование выбранной очереди
            cout << "Очередь скопирована. Номер очереди: " << count++ << endl;
            system("pause");
            break;

        case 6:
            if (count == 1)
            {
                cout << "Существует только одна очередь" << endl;
                system("pause");
                break;
            }

            cout << "С какой очередью будет произведено слияние? (0 - " << count - 1 << ") :  ";
            cin >> choise;
            system("cls");

            if ((choise < 0) || (choise == number) || (choise >= count))
            {
                cout << "Некорректное значение. Объединение не произведено" << endl;
                system("pause");
                break;
            }

            queue[count].merger(queue[number], queue[choise]);
            cout << "Объединение произведено. Номер очереди результата: " << count << endl;
            count++;
            system("pause");
            break;

        case 7:
            if (count == 1)
            {
                cout << "Существует только одна очередь" << endl;
                system("pause");
                break;
            }

            cout << "Вы находитесь в очереди № " << number << endl;
            cout << "Введите номер очереди (от 0 до " << count - 1 << ", кроме " << number << ", так как она сейчас используется), на которую следует переключиться: ";
            cin >> choise;
            system("cls");
            if ((choise < 0) || (choise == number) || (choise >= count))
            {
                cout << "Некорректное значение. Переключение не выполнено" << endl;
            }
            else
            {
                number = choise;
                cout << "Текущая очередь:" << endl;
                queue[number].out(); // вывод на экран выбранной очереди
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

    int Number_Q; // количество очередей
    int Type_son; // номер типа наследования

    cout << "Введите количество очередей" << endl;
    cin >> Number_Q;
    system("cls");

    sub1* Object1 = NULL;
    sub2* Object2 = NULL;
    sub3* Object3 = NULL;

    cout << "Выберете тип наследования" << endl;
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
        cout << "некорректный ввод";
        break;
    }

    return 0;
}
