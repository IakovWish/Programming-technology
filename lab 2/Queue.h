#pragma once

struct Unit
{
	int value = 0; // �������� �������� �������
	Unit* prev = 0; // ������ �� ���������� ������� �������
};

class Queue
{
	friend Queue operator++ (Queue& tmp_queue);
	friend Queue operator-- (Queue& tmp_queue);

private:
	Unit* last = 0; // ����� �������

protected:
	int size; // ������ �������
	void push(int value); // ���������� ��������� � ����� �������

public:
	explicit Queue(int sizer); // ����������� c �����������
	Queue(); // �����������
	Queue(const Queue& tmp_queue); // ����������� �����������
	~Queue(); // ����������
	void out();
	Queue& operator = (const Queue& tmp_queue);
	Queue operator++ (int);
	Queue operator-- (int);
	bool operator! ();
};