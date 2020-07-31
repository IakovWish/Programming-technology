#pragma once

struct Unit
{
    int value = 0; // �������� �������� ��������
    Unit* prev = 0; // ��������� �� ���������� ��-�
};

class Queue
{
private:
    Unit* last = 0; // ��������� �� ����� �������

protected:
    int size; // ������ �������
    Unit* get_last(); // ���������� ��������� �� ��������� ������� ��� �����������

public:
    Queue(); // �����������
    ~Queue(); // ����������
    void push(int data); // ���������� �������� � �������
    int pop(); // ���������� ��������
    void out(); // ����� �� �����
    void copy(Queue& ob); // ����������� �������
    void merger(Queue& ob1, Queue& ob2); // ������� �������
    bool check(); // ��������� �� ������� �������
};