#pragma once
#include "warrior.h"
class Assassin : public Warrior
{
public:
	Assassin(void);
	~Assassin(void);
	string getName();
	int getAllignment();
	void perform();
private:
	int allignment; //1 - good, 2- bad
	string name;
};

