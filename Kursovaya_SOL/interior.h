#pragma once
#include "object.h"

class interior : public object
{
public:
	float time;
	//���� ��������, ��� �� ��� �����������, �� ����� �������� �����...
	//������������� ��������� anim � path �����
};

class bed : public interior
{
public:
	int sleep;

};

class computer : public interior
{
	;
};

class : public interior
{

};

class toilet : public interior
{
	;
};

class shower : public interior
{
	;
};