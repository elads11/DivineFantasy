#include "StdAfx.h"
#include "Knight.h"


Knight::Knight(void) : allignment(1), name("Knight")
{
}


Knight::~Knight(void)
{
}

string Knight::getName(){
	return name; 
}

int Knight::getAllignment(){
	return allignment;
}

void Knight::perform(){
	setExtraStat(hp+monstersKilled); 
	if (getExtraStat() == 30){
		artefacts[0] = 1;
		artefacts[1] = 1;
		level = 2;
		MessageBox(0, L"Your ability grew so much that you just craft the sword", L"Knight Skill", MB_OK);
	}
}