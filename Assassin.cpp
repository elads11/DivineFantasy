#include "StdAfx.h"
#include "Assassin.h"


Assassin::Assassin(void) : allignment(2), name("Assassin")
{
}


Assassin::~Assassin(void)
{
}

string Assassin::getName(){
	return name; 
}

int Assassin::getAllignment(){
	return allignment;
}

void Assassin::perform(){
	if (monstersKilled>0){
		gold += monstersKilled;
		monstersKilled = 0;
		MessageBox(0, L"You sell the poor enemy's soul for gold", L"Assassin Skill", MB_OK);
	}
}