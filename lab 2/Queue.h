#pragma once

struct Unit
{
	int value = 0; // значение элемента очереди
	Unit* prev = 0; // ссылка на предыдущий элемент очереди
};

class Queue
{
	friend Queue operator++ (Queue& tmp_queue);
	friend Queue operator-- (Queue& tmp_queue);

private:
	Unit* last = 0; // конец очереди

protected:
	int size; // размер очереди
	void push(int value); // добавление элементов в конец очереди

public:
	explicit Queue(int sizer); // конструктор c параметрами
	Queue(); // конструктор
	Queue(const Queue& tmp_queue); // конструктор копирования
	~Queue(); // деструктор
	void out();
	Queue& operator = (const Queue& tmp_queue);
	Queue operator++ (int);
	Queue operator-- (int);
	bool operator! ();
};