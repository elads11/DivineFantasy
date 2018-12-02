#include "StdAfx.h"
#include "Wizard.h"


Wizard::Wizard(void) : allignment(1), name("Wizard")
{	
}


Wizard::~Wizard(void)
{
}

string Wizard::getName(){
	return name; 
}

int Wizard::getAllignment(){
	return allignment;
}

void Wizard::perform(){
	setExtraStat(getExtraStat() + 1);
	if (getExtraStat() == 2){
		++hp;
		setExtraStat(0);
		MessageBox(0, L"You have 2 mana and convert your knowledge to get stronger. HP + 1", L"Wizard Skill", MB_OK);
	}
}