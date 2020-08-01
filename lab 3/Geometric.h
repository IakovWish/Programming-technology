#pragma once
#include "Progression.h"
#include <string>

class Geometric : public Progression
{
private:

protected:

public:
	double progression_amount(int value) override;
	Geometric(); // конструктор
	Geometric(string path); // конструктор с параметрами
	Geometric(const Geometric& tmp_Geometriс); // конструктор копирования
	~Geometric() override;
};