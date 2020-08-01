#pragma once
#include <string>

using namespace std;

class Progression
{
private:

protected:
	double member1 = 0;
	double const_diff_att = 0;
	virtual double progression_amount(int value) = 0;

public:
	string path;
	int val = 0; // ���������� ��������, ����� ������������ ������ ��� ������ �� �����
	double res = 0.0; // ����� ����������, ���� ������������ ������ ��� ������ �� �����
	virtual ~Progression();
	void input(double result, int value);
	void output();
	void reader();
};