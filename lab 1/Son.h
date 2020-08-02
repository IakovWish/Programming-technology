#pragma once

#include"Queue.h"

class sub1 : public Queue
{
public:
    int min_unit_finder();
};

class sub2 : protected Queue
{
public:
    void push(int data); // добавление элемента в очередь
    int pop(); // извлечения элемента
    void out(); // вывод на экран
    void copy(sub2& ob); // Копирование очереди
    void merger(sub2& ob1, sub2& ob2);
    bool check(); // Проверяем на пустоту
    int min_unit_finder();
};

class sub3 : private Queue
{
public:
    void push(int data); //добавление элемента в очередь
    int pop(); // извлечения элемента
    void out(); // вывод на экран
    void copy(sub3& ob); // Копирование очереди
    void merger(sub3& ob1, sub3& ob2);
    bool check(); // Проверяем на пустоту
    int min_unit_finder();
};
