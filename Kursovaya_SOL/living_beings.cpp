#include "living_beings.h"


living_beings::living_beings()
{
	std::cin >> name;
	std::cin >> gender;//переписать через выбор пола на кнопочку
}

void living_beings::SetRelationshipStatusBar(int scale_rs)
{
	this -> relationship = scale_rs;
}

int living_beings::GetRelationshipStatusBar()
{
	return this -> relationship;
}

void living_beings::SetFullness(int full)
{
	this->fullness = full;
}

int living_beings::GetFullness()
{
	return this->fullness;
}

void living_beings::SetEnergy(int energy_sleep)
{
	this->energy = energy_sleep;
}

int living_beings::GetEnergy()
{
	return this->energy;
}

void living_beings::SetNeed(int needness)
{
	this->need = needness;
}

int living_beings::GetNeed()
{
	return this->need;
}

void living_beings::SetHygiene(int hyg)
{
	this->hygiene = hyg;
}

int living_beings::GetHygiene()
{
	return this->hygiene;
}

void living_beings::SetPlayful(int playfullness)
{
	this->playful = playfullness;
}

int living_beings::GetPlayful()
{
	return this->playful;
}