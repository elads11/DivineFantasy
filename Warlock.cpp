#include "StdAfx.h"
#include "Warlock.h"


Warlock::Warlock(void) : allignment(2), name("Warlock")
{
}


Warlock::~Warlock(void)
{
}

string Warlock::getName(){
	return name; 
}

int Warlock::getAllignment(){
	return allignment;
}

void Warlock::perform(){
	setExtraStat(getExtraStat() + 1);
	if (monstersKilled>0){
		setExtraStat(getExtraStat() + 1);
		monstersKilled = 0;
	}
	if (getExtraStat() == 5){
		++gold;
		++hp;
		setExtraStat(0);
		MessageBox(0, L"You have 5 mana and convert it to 1 gold and 1 HP", L"Warlock Skill", MB_OK);
	}
}