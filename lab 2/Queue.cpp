#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() :size(0) // �����������
{

}

Queue::Queue(int sizer) // ����������� c �����������
{
	this->size = sizer;
}

Queue::Queue(const Queue& tmp_queue1) :size(0) // ����������� �����������
{
	int* arr = new int[tmp_queue1.size]; // ������� ������ �������� � ����� �������
	Unit* buf = tmp_queue1.last; // ��������� ���������� ���������

	for (int i = tmp_queue1.size - 1; i >= 0; i--) // �������� � ������� � ����� � ������
	{
		arr[i] = buf->value;
		buf = buf->prev; // ���� � ������
	}

	for (int i = 0; i < tmp_queue1.size; i++) // ��������� ��� �������� � ����� ������� �� �������
	{
		this->push(arr[i]);
	}

	delete[] arr;
}

Queue::~Queue() // ����������
{
	while (this->size > 0)
	{
		Unit* buf = last;
		last = buf->prev;
		delete buf;
		size--;
	}
}

void Queue::out() // ����� �� �����
{
	Unit* buf = last;
	while (buf->prev != 0)
	{
		cout << buf->value << " -> ";
		buf = buf->prev;
	}

	cout << buf->value << endl;
}

void Queue::push(int value) // ���������� ��������� � ����� �������
{
	Unit* buf = new(Unit); // �������� ������ ��� ����� �������
	buf->prev = last; // ����� ������� ��������� �� ������ ���������
	buf->value = value;
	last = buf; // ����� ������� ���������
	size++;
}

bool Queue::operator! () // �������� �� �������
{
	if (size == 0)
	{
		cout << "������� �����" << endl;
		return false;
	}

	return true;
}

Queue& Queue::operator = (const Queue& tmp_queue2) // ���������� ��������� ������������
{
	while (this->size > 0) // ������� ������ ��������
	{
		Unit* tmp_unit = last; // ��������� ���������� ���������
		last = tmp_unit->prev; // ��������� ���������� ����������
		delete tmp_unit; // ��������� ������ �� �����
		size--;
	}

	int* masValueQueue = new int[tmp_queue2.size]; // ������� ������ �������� � ����� �������
	Unit* tmp_unit1 = tmp_queue2.last; // ��������� ���������� ���������
	for (int i = tmp_queue2.size - 1; i >= 0; i--)
	{
		masValueQueue[i] = tmp_unit1->value; // ���������� � ����� � �����
		tmp_unit1 = tmp_unit1->prev; // ��������� ���� �� ����� � ������
	}
	for (int i = 0; i < tmp_queue2.size; i++)
	{
		this->push(masValueQueue[i]); // ��������� � �������� � �� ���������� �������� � �������
	}
	delete[] masValueQueue; // ��������� ������ ������ �� �����
	return *this; // ���������� ��������� �� �������
}

Queue Queue::operator++ (int) // ���������� ��������� ++ (����������� �����, �����) ��������� ������� � �������
{
	Queue tmp_queue(*this);
	cout << "������� ��������: ";
	int value;
	cin >> value;
	Unit* tmp_unit = new(Unit); // �������� ������ ��� ����� �������
	tmp_unit->prev = last; // ����� ������� ��������� �� ������ ���������
	tmp_unit->value = value;
	last = tmp_unit; // ����� ������� ���������
	size += 1;
	cout << "������� ��������" << endl;
	return tmp_queue;
}

Queue Queue::operator-- (int) // ���������� ��������� -- (����������� �����) ����������� ������� �� �������
{
	Queue tmp_queue(*this);
	int now_ex = 0;
	if (size == 1)
	{
		now_ex = last->value; // ��������� �������� ������� �������� � �������
		last = 0;
		size--;
	}
	else
	{
		Unit* tmp_unit = last;
		while (tmp_unit->prev->prev != 0) // ���� �� ������ �� ������� � �������
		{
			tmp_unit = tmp_unit->prev;
		}
		now_ex = tmp_unit->prev->value; // ���������� �������� ������� � �������
		tmp_unit->prev = nullptr; // ����� ������ ��������� �� ����
		delete tmp_unit->prev; // ������� ������ ������
		size--;
	}

	cout << "�������� ������� " << now_ex << endl;
	return tmp_queue;
}

Queue operator++ (Queue& tmp_queue) // ���������� ��������� ++ (���������� �����, ������������� �������) ����������� ��� ����� � ������� �� 1
{
	Unit* tmp_unit = tmp_queue.last; // ��������� ������� ����� ����������
	while (tmp_unit->prev != 0) // ���� �� ������ �� ������� � �������
	{
		tmp_unit->value += 1; // ���������� 1 � �������� �������� ��������
		tmp_unit = tmp_unit->prev; // ���� � ������
	}
	tmp_unit->value += 1; // � ���������� ���� ���� ���������
	return tmp_queue;
}

Queue operator-- (Queue& tmp_queue) // ���������� ��������� -- (���������� �����, ������������� �������) ��������� ��� ����� � ������� �� 1
{
	Unit* tmp_unit = tmp_queue.last; // ��������� ������� ����� ����������
	while (tmp_unit->prev != 0) // ���� �� ������ �� ������� � �������
	{
		tmp_unit->value -= 1; // �������� 1 � �������� �������� ��������
		tmp_unit = tmp_unit->prev; // ���� � ������
	}
	tmp_unit->value -= 1; // �� ���������� ���� ���� ������
	return tmp_queue;
}