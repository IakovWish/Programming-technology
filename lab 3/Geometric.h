#pragma once
#include "Progression.h"
#include <string>

class Geometric : public Progression
{
private:

protected:

public:
	double progression_amount(int value) override;
	Geometric(); // �����������
	Geometric(string path); // ����������� � �����������
	Geometric(const Geometric& tmp_Geometri�); // ����������� �����������
	~Geometric() override;
};