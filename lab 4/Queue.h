#pragma once
#include <iostream>
using namespace std;

template <typename T2>
class Unit
{
private:
	T2 value = 0; // значение элемента очереди
	Unit<T2>* prev = 0; // ссылка на предыдущий элемент очереди

public:
	Unit() : value(0) // конструктор 
	{

	};

	Unit(T2 val) : value(0) // конструктор 
	{
		value = val;
	};

	~Unit() // деструктор
	{

	}

	T2 get_value()
	{
		return value;
	}

	Unit<T2>*& get_prev()
	{
		return prev;
	}

	void set_prev(Unit<T2>* new_prev)
	{
		prev = new_prev;
	}

	void set_value(T2 new_val)
	{
		value = new_val;
	}
};

//struct Unit
//{
//	T2 value = 0; // значение элемента очереди
//	Unit<T2> *prev = 0; // ссылка на предыдущий элемент очереди
//};

template <typename T2>
class Queue
{
private:
	Unit<T2>* last = 0; // конец очереди
	int size; // размер очереди

protected:

public:
	Queue() : size(0) // конструктор очереди 
	{

	};

	Queue(int value) // конструктор очереди с параметром
	{
		for (int i = 0; i < value; i++)
		{
			this->push((130.0 + rand() % 56) / (2.0 + rand() % 2));
		}
	};

	~Queue() // деструктор очереди
	{
		while (this->size > 0) // пока размер очереди больше нуля
		{
			this->pop();
		}
		system("cls");
	};

	void push(T2 value) // добавление элементов в конец очереди
	{
		Unit<T2>* new_unit = new(Unit<T2>); // выделяем память под новый элемент
		new_unit->/*prev*/set_prev(last)/* = last*/; // новый элемент будет ссылаться на последний
		new_unit->/*value*/set_value(value)/* = value*/; // изменяем значение нового элемента
		last = new_unit; // последний элемент изменился
		size++; // добавили один элемент
	};

	void pop() // извлекаем первый элемент из очереди
	{
		T2 now_ex = 0; // извлеченный элемент
		if (size == 1) // если в очереди 1 элемент
		{
			now_ex = last->/*value*/get_value(); // извлекаемый элемент - последний
			delete last; // удаляем указатель на него
			last = nullptr; // и обнуляем
		}
		else // если больше одного элемента, значит адрес извлекаемого хранится во втором
		{
			Unit<T2>* current = last; // создаем переменную, которая будет идти от конца
			while (current->/*prev*/get_prev()->/*prev*/get_prev() != nullptr) // пока не дойдем до второго в очереди
			{
				current = current->get_prev()/*prev*/; // идем от конца к началу
			}
			now_ex = current->/*prev*/get_prev()->/*value*/get_value(); // запомнили извлекаемого
			delete current->/*prev*/get_prev(); // удаляем первый элемент
			current->/*prev*/set_prev(nullptr)/* = nullptr*/; // бывший второй элемент теперь будет ссылаться на первый
		}
		size--; // извлекли один элемент
		cout << "Извлечен элемент " << now_ex << endl;
		//return now_ex; // выводим извлеченного на экран
	}

	void copyQueue(Queue<T2>& Queue_tmp) // копирование очередей
	{
		T2* masValueQueue = new T2[Queue_tmp.size]; // создаем массив размером с количество элементов копируемой очереди
		Unit<T2>* current = Queue_tmp.last; // создаем переменную с помощью которой будем идти от конца к началу
		for (int i = Queue_tmp.size - 1; i >= 0; i--) // начиная с конца...
		{
			masValueQueue[i] = current->/*value*/get_value(); // ...записываем все элементы очереди в массив
			current = current->/*prev*/get_prev(); // идем от конца к началу
		}
		for (int i = 0; i < Queue_tmp.size; i++) // теперь вставляем все элементы в правильном порядке...
		{
			this->push(masValueQueue[i]); // в новую очередь
		}
		delete[] masValueQueue; // временный элемент больше не нужен
	};

	void operator! () // проверка на пустоту
	{
		if (size == 0) // если очередь пуста...
		{
			throw "Очередь пуста";
		}
	};

	friend istream& operator >> (istream& in, Queue<T2>& Queue_tmp) // перегруженный ввод
	{
		T2 value; // вводимая переменная
		cout << "Введите значение: ";
		cin >> value; // вводим новый элемент
		Queue_tmp.push(value); // вставляем в очередь
		return in;
	}

	friend ostream& operator << (ostream& os, Queue<T2>& Queue_tmp) // перегруженный вывод
	{
		Unit<T2>* current = Queue_tmp.last; // создаем переменную, идем от канца к началу
		while (current->/*prev*/get_prev() != 0) // пока не дойдем до первого элемента
		{
			os << current->/*value*/get_value() << " -> "; // выводим значение текущего
			current = current->/*prev*/get_prev(); // идем к началу
		}
		os << current->/*value*/ get_value() << endl; // последний выводим отдельно
		return os;
	}

	void operator + (Queue<T2>& Queue_tmp) // сложение двух очередей
	{
		if (size != Queue_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Сложение очередей невозможно" << endl;
		}
		else
		{
			Unit<T2>* current_item1 = last; // указываем на конец текущей очереди
			Unit<T2>* current_item2 = Queue_tmp.last; // и на конец второй
			while (current_item1->/*prev*/get_prev() != 0) // пока не дойдем до первого элемента
			{
				current_item1->set_value(current_item1->/*value*/get_value() + current_item2->/*value*/get_value()); // прибавляем к значению текущей значение второй
				current_item1 = current_item1->get_prev()/*prev*/; // двигаем к началу текущую
				current_item2 = current_item2->get_prev()/*prev*/; // двигаем к началу вторую
			}
			current_item1->set_value(current_item1->get_value()/*value*/ + current_item2->/*value*/get_value()); // к первому тоже прибавляем
			cout << "Новая очередь " << *this; // выводим на экран
		}
	}

	void operator - (Queue<T2>& Queue_tmp) // вычитание второй очереди из первой
	{
		if (size != Queue_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Вычитание очередей невозможно" << endl;
		}
		else
		{
			Unit<T2>* current_item1 = last; // указываем на конец текущей очереди
			Unit<T2>* current_item2 = Queue_tmp.last; // и на конец второй
			while (current_item1->get_prev()/*prev*/ != 0) // пока не дойдем до первого элемента
			{
				current_item1->set_value(current_item1->get_value() - current_item2->/*value*/get_value()); // вычитаем от значения текущей значение второй
				current_item1 = current_item1->get_prev()/*prev*/; // двигаем к началу текущую
				current_item2 = current_item2->get_prev()/*prev*/; // двигаем к началу вторую
			}
			current_item1->set_value(current_item1->/*value*/get_value() - current_item2->/*value*/get_value()); // из первого тоже вычитаем
			cout << "Новая очередь " << *this;  // выводим на экран
		}
	}
};