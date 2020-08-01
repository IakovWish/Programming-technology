#pragma once
#include <iostream>
using namespace std;

template <typename T2>
class Unit
{
private:
	T2 value = 0; // �������� �������� �������
	Unit<T2>* prev = 0; // ������ �� ���������� ������� �������

public:
	Unit() : value(0) // ����������� 
	{

	};

	Unit(T2 val) : value(0) // ����������� 
	{
		value = val;
	};

	~Unit() // ����������
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
//	T2 value = 0; // �������� �������� �������
//	Unit<T2> *prev = 0; // ������ �� ���������� ������� �������
//};

template <typename T2>
class Queue
{
private:
	Unit<T2>* last = 0; // ����� �������
	int size; // ������ �������

protected:

public:
	Queue() : size(0) // ����������� ������� 
	{

	};

	Queue(int value) // ����������� ������� � ����������
	{
		for (int i = 0; i < value; i++)
		{
			this->push((130.0 + rand() % 56) / (2.0 + rand() % 2));
		}
	};

	~Queue() // ���������� �������
	{
		while (this->size > 0) // ���� ������ ������� ������ ����
		{
			this->pop();
		}
		system("cls");
	};

	void push(T2 value) // ���������� ��������� � ����� �������
	{
		Unit<T2>* new_unit = new(Unit<T2>); // �������� ������ ��� ����� �������
		new_unit->/*prev*/set_prev(last)/* = last*/; // ����� ������� ����� ��������� �� ���������
		new_unit->/*value*/set_value(value)/* = value*/; // �������� �������� ������ ��������
		last = new_unit; // ��������� ������� ���������
		size++; // �������� ���� �������
	};

	void pop() // ��������� ������ ������� �� �������
	{
		T2 now_ex = 0; // ����������� �������
		if (size == 1) // ���� � ������� 1 �������
		{
			now_ex = last->/*value*/get_value(); // ����������� ������� - ���������
			delete last; // ������� ��������� �� ����
			last = nullptr; // � ��������
		}
		else // ���� ������ ������ ��������, ������ ����� ������������ �������� �� ������
		{
			Unit<T2>* current = last; // ������� ����������, ������� ����� ���� �� �����
			while (current->/*prev*/get_prev()->/*prev*/get_prev() != nullptr) // ���� �� ������ �� ������� � �������
			{
				current = current->get_prev()/*prev*/; // ���� �� ����� � ������
			}
			now_ex = current->/*prev*/get_prev()->/*value*/get_value(); // ��������� ������������
			delete current->/*prev*/get_prev(); // ������� ������ �������
			current->/*prev*/set_prev(nullptr)/* = nullptr*/; // ������ ������ ������� ������ ����� ��������� �� ������
		}
		size--; // �������� ���� �������
		cout << "�������� ������� " << now_ex << endl;
		//return now_ex; // ������� ������������ �� �����
	}

	void copyQueue(Queue<T2>& Queue_tmp) // ����������� ��������
	{
		T2* masValueQueue = new T2[Queue_tmp.size]; // ������� ������ �������� � ���������� ��������� ���������� �������
		Unit<T2>* current = Queue_tmp.last; // ������� ���������� � ������� ������� ����� ���� �� ����� � ������
		for (int i = Queue_tmp.size - 1; i >= 0; i--) // ������� � �����...
		{
			masValueQueue[i] = current->/*value*/get_value(); // ...���������� ��� �������� ������� � ������
			current = current->/*prev*/get_prev(); // ���� �� ����� � ������
		}
		for (int i = 0; i < Queue_tmp.size; i++) // ������ ��������� ��� �������� � ���������� �������...
		{
			this->push(masValueQueue[i]); // � ����� �������
		}
		delete[] masValueQueue; // ��������� ������� ������ �� �����
	};

	void operator! () // �������� �� �������
	{
		if (size == 0) // ���� ������� �����...
		{
			throw "������� �����";
		}
	};

	friend istream& operator >> (istream& in, Queue<T2>& Queue_tmp) // ������������� ����
	{
		T2 value; // �������� ����������
		cout << "������� ��������: ";
		cin >> value; // ������ ����� �������
		Queue_tmp.push(value); // ��������� � �������
		return in;
	}

	friend ostream& operator << (ostream& os, Queue<T2>& Queue_tmp) // ������������� �����
	{
		Unit<T2>* current = Queue_tmp.last; // ������� ����������, ���� �� ����� � ������
		while (current->/*prev*/get_prev() != 0) // ���� �� ������ �� ������� ��������
		{
			os << current->/*value*/get_value() << " -> "; // ������� �������� ��������
			current = current->/*prev*/get_prev(); // ���� � ������
		}
		os << current->/*value*/ get_value() << endl; // ��������� ������� ��������
		return os;
	}

	void operator + (Queue<T2>& Queue_tmp) // �������� ���� ��������
	{
		if (size != Queue_tmp.size) // ���� ������ �� ���������, ������ �������� �� �����
		{
			cout << "�������� �������� ����������" << endl;
		}
		else
		{
			Unit<T2>* current_item1 = last; // ��������� �� ����� ������� �������
			Unit<T2>* current_item2 = Queue_tmp.last; // � �� ����� ������
			while (current_item1->/*prev*/get_prev() != 0) // ���� �� ������ �� ������� ��������
			{
				current_item1->set_value(current_item1->/*value*/get_value() + current_item2->/*value*/get_value()); // ���������� � �������� ������� �������� ������
				current_item1 = current_item1->get_prev()/*prev*/; // ������� � ������ �������
				current_item2 = current_item2->get_prev()/*prev*/; // ������� � ������ ������
			}
			current_item1->set_value(current_item1->get_value()/*value*/ + current_item2->/*value*/get_value()); // � ������� ���� ����������
			cout << "����� ������� " << *this; // ������� �� �����
		}
	}

	void operator - (Queue<T2>& Queue_tmp) // ��������� ������ ������� �� ������
	{
		if (size != Queue_tmp.size) // ���� ������ �� ���������, ������ �������� �� �����
		{
			cout << "��������� �������� ����������" << endl;
		}
		else
		{
			Unit<T2>* current_item1 = last; // ��������� �� ����� ������� �������
			Unit<T2>* current_item2 = Queue_tmp.last; // � �� ����� ������
			while (current_item1->get_prev()/*prev*/ != 0) // ���� �� ������ �� ������� ��������
			{
				current_item1->set_value(current_item1->get_value() - current_item2->/*value*/get_value()); // �������� �� �������� ������� �������� ������
				current_item1 = current_item1->get_prev()/*prev*/; // ������� � ������ �������
				current_item2 = current_item2->get_prev()/*prev*/; // ������� � ������ ������
			}
			current_item1->set_value(current_item1->/*value*/get_value() - current_item2->/*value*/get_value()); // �� ������� ���� ��������
			cout << "����� ������� " << *this;  // ������� �� �����
		}
	}
};