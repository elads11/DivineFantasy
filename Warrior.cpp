#include "StdAfx.h"
#include "Warrior.h"


Warrior::Warrior(void)
{
	setExtraStat(0);
}


Warrior::~Warrior(void)
{
}

int Warrior::getExtraStat(){ return willPower; }
void Warrior::setExtraStat(int x){ willPower = x; }
