#pragma once
#include "Progression.h"
#include <string>

using namespace std;

class Arithmetic : public Progression
{
private:

protected:

public:
	double progression_amount(int value) override;
	Arithmetic(); // �����������
	Arithmetic(string path); // ����������� � �����������
	Arithmetic(const Arithmetic& tmp_Arithmetic); // ����������� �����������
	~Arithmetic() override;
};