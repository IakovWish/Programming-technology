#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() :size(0) // конструктор
{

}

Queue::Queue(int sizer) // конструктор c параметрами
{
	this->size = sizer;
}

Queue::Queue(const Queue& tmp_queue1) :size(0) // конструктор копирования
{
	int* arr = new int[tmp_queue1.size]; // создаем массив размером с длину очереди
	Unit* buf = tmp_queue1.last; // временный становится последним

	for (int i = tmp_queue1.size - 1; i >= 0; i--) // копируем с очередь с конца в массив
	{
		arr[i] = buf->value;
		buf = buf->prev; // идем к началу
	}

	for (int i = 0; i < tmp_queue1.size; i++) // вставляем все элементы в новую очередь по порядку
	{
		this->push(arr[i]);
	}

	delete[] arr;
}

Queue::~Queue() // деструктор
{
	while (this->size > 0)
	{
		Unit* buf = last;
		last = buf->prev;
		delete buf;
		size--;
	}
}

void Queue::out() // вывод на экран
{
	Unit* buf = last;
	while (buf->prev != 0)
	{
		cout << buf->value << " -> ";
		buf = buf->prev;
	}

	cout << buf->value << endl;
}

void Queue::push(int value) // добавление элементов в конец очереди
{
	Unit* buf = new(Unit); // выделяем память под новый элемент
	buf->prev = last; // новый элемент ссылается на старый последний
	buf->value = value;
	last = buf; // конец очереди поменялся
	size++;
}

bool Queue::operator! () // проверка на пустоту
{
	if (size == 0)
	{
		cout << "Очередь пуста" << endl;
		return false;
	}

	return true;
}

Queue& Queue::operator = (const Queue& tmp_queue2) // перегрузка оператора присваивания
{
	while (this->size > 0) // удаляем старые элементы
	{
		Unit* tmp_unit = last; // временный становится последним
		last = tmp_unit->prev; // последний становится предыдущим
		delete tmp_unit; // временный больше не нужен
		size--;
	}

	int* masValueQueue = new int[tmp_queue2.size]; // создаем массив размером с длину очереди
	Unit* tmp_unit1 = tmp_queue2.last; // временный становится последним
	for (int i = tmp_queue2.size - 1; i >= 0; i--)
	{
		masValueQueue[i] = tmp_unit1->value; // записываем в масив с конца
		tmp_unit1 = tmp_unit1->prev; // временный идет от конца к началу
	}
	for (int i = 0; i < tmp_queue2.size; i++)
	{
		this->push(masValueQueue[i]); // вставляем с перевого и до последнего элемента в очередь
	}
	delete[] masValueQueue; // временный массив больше не нужен
	return *this; // возвращаем указатель на очередь
}

Queue Queue::operator++ (int) // перегрузка оператора ++ (постфиксная форма, метод) добавляет элемент в очередь
{
	Queue tmp_queue(*this);
	cout << "Введите значение: ";
	int value;
	cin >> value;
	Unit* tmp_unit = new(Unit); // выделяем память под новый элемент
	tmp_unit->prev = last; // новый элемент ссылается на старый последний
	tmp_unit->value = value;
	last = tmp_unit; // конец очереди поменялся
	size += 1;
	cout << "Элемент добавлен" << endl;
	return tmp_queue;
}

Queue Queue::operator-- (int) // перегрузка оператора -- (постфиксная форма) вытаскивает элемент из очереди
{
	Queue tmp_queue(*this);
	int now_ex = 0;
	if (size == 1)
	{
		now_ex = last->value; // запомнили значение первого элемента в очереди
		last = 0;
		size--;
	}
	else
	{
		Unit* tmp_unit = last;
		while (tmp_unit->prev->prev != 0) // пока не дойдем до второго в очереди
		{
			tmp_unit = tmp_unit->prev;
		}
		now_ex = tmp_unit->prev->value; // запоминаем значение первого в очереди
		tmp_unit->prev = nullptr; // новый первый ссылается на нуль
		delete tmp_unit->prev; // удаляем старый первый
		size--;
	}

	cout << "Извлечен элемент " << now_ex << endl;
	return tmp_queue;
}

Queue operator++ (Queue& tmp_queue) // перегрузка оператора ++ (префиксная форма, дружественная функция) увеличивает все числа в очереди на 1
{
	Unit* tmp_unit = tmp_queue.last; // временный элемент равен последнему
	while (tmp_unit->prev != 0) // пока не дойдем до первого в очереди
	{
		tmp_unit->value += 1; // прибавляем 1 к значению текущего элемента
		tmp_unit = tmp_unit->prev; // идем к началу
	}
	tmp_unit->value += 1; // к последнему тоже надо прибавить
	return tmp_queue;
}

Queue operator-- (Queue& tmp_queue) // перегрузка оператора -- (префиксная форма, дружественная функция) уменьшает все числа в очереди на 1
{
	Unit* tmp_unit = tmp_queue.last; // временный элемент равен последнему
	while (tmp_unit->prev != 0) // пока не дойдем до первого в очереди
	{
		tmp_unit->value -= 1; // отнимаем 1 к значению текущего элемента
		tmp_unit = tmp_unit->prev; // идем к началу
	}
	tmp_unit->value -= 1; // от последнего тоже надо отнять
	return tmp_queue;
}