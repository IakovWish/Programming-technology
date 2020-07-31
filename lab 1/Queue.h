#pragma once

struct Unit
{
    int value = 0; // значение текущего элемента
    Unit* prev = 0; // указатель на предыдущий эл-т
};

class Queue
{
private:
    Unit* last = 0; // Указатель на конец очереди

protected:
    int size; // размер очереди
    Unit* get_last(); // Возвращаем указатель на последний элемент для наследников

public:
    Queue(); // конструктор
    ~Queue(); // деструктор
    void push(int data); // добавление элемента в очередь
    int pop(); // извлечения элемента
    void out(); // вывод на экран
    void copy(Queue& ob); // Копирование очереди
    void merger(Queue& ob1, Queue& ob2); // Слияние очереди
    bool check(); // Проверяем на пустоту очередь
};