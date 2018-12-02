#pragma once
#include "warrior.h"
class Knight : public Warrior
{
public:
	Knight(void);
	~Knight(void);
	string getName();
	int getAllignment();
	void perform();
private:
	int allignment; //1 - good, 2- bad
	string name;
};

