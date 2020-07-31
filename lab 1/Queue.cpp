#include <stdio.h>
#include "Queue.h"
#include <iostream>

using namespace std;

Unit* Queue::get_last()
{
    return last;
}

bool Queue::check()
{
    if (size == 0)
    {
        cout << "Очередь пуста" << endl;
        system("pause");
        return false;
    }

    return true;
}

Queue::Queue()
{
    size = 0;
};

Queue:: ~Queue()
{
    while (size > 0)
    {
        Unit* buf = last;
        last = buf->prev;
        delete buf;
        size--;
    };
}

void Queue::push(int value)
{
    Unit* buff = new Unit; // выделяем память под новый элемент
    buff->prev = last; // новый элемент ссылается на старый последний
    buff->value = value;
    last = buff;
    size++;
}

int Queue::pop(void)
{
    int now_ex = 0;
    Unit* buf = last;
    if (buf->prev == nullptr) // если в очереди 1 элемент
    {
        now_ex = buf->value;
        delete last;
        last = nullptr;
        size--;
    }
    else
    {
        while (buf->prev->prev != nullptr) // пока не дойдем до второго в очереди
        {
            buf = (buf->prev);
        }
        now_ex = buf->prev->value;
        delete buf->prev;
        buf->prev = nullptr;
        size--;
    }
    return now_ex;
}

void Queue::out()
{
    Unit* buf = last;

    while (buf->prev != nullptr) // если это был не последний, то...
    {
        cout << buf->value << "  ->  ";
        buf = buf->prev; // берем следующий
    };

    cout << buf->value << endl; // вписываем последний
}

void Queue::copy(Queue& ob) // передаем текущую очередь
{
    int* arr = new int[ob.size]; // создаем указатель на массив равный количеству элементов в очереди
    Unit* ptr = ob.last;

    for (int i = ob.size - 1; i >= 0; i--)
    {
        arr[i] = ptr->value;
        ptr = ptr->prev;
    }

    for (int i = 0; i < ob.size; i++)
    {
        this->push(arr[i]); // указатель на обьект на котором вызвана функция
    }

    delete[] arr;
    this->out();
}

void Queue::merger(Queue& ob1, Queue& ob2)
{
    int* arr = new int[ob1.size];
    Unit* ptr1 = ob1.last;

    for (int i = ob1.size - 1; i >= 0; i--)
    {
        arr[i] = ptr1->value;
        ptr1 = ptr1->prev;
    }

    for (int i = 0; i < ob1.size; i++)
    {
        this->push(arr[i]);
    }

    delete[] arr;

    int* arr2 = new int[ob2.size];
    Unit* ptr2 = ob2.last;

    for (int i = ob2.size - 1; i >= 0; i--)
    {
        arr2[i] = ptr2->value;
        ptr2 = ptr2->prev;
    }

    for (int i = 0; i < ob2.size; i++)
    {
        push(arr2[i]);
    }

    delete[] arr2;
    this->out();
}