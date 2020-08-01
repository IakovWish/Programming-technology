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
	Arithmetic(); // конструктор
	Arithmetic(string path); // конструктор с параметрами
	Arithmetic(const Arithmetic& tmp_Arithmetic); // конструктор копирования
	~Arithmetic() override;
};