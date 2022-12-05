#pragma once
#include "object.h"

class interior : public object
{
public:
	float time;
	//путь прописан, как бы это реализовать, мб пойти классами далее...
	//использование предметов anim и path также
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