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
    void push(int data); // ���������� �������� � �������
    int pop(); // ���������� ��������
    void out(); // ����� �� �����
    void copy(sub2& ob); // ����������� �������
    void merger(sub2& ob1, sub2& ob2);
    bool check(); // ��������� �� �������
    int min_unit_finder();
};

class sub3 : private Queue
{
public:
    void push(int data); //���������� �������� � �������
    int pop(); // ���������� ��������
    void out(); // ����� �� �����
    void copy(sub3& ob); // ����������� �������
    void merger(sub3& ob1, sub3& ob2);
    bool check(); // ��������� �� �������
    int min_unit_finder();
};