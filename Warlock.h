#pragma once
#include "mage.h"
class Warlock : public Mage
{
public:
	Warlock(void);
	~Warlock(void);
	string getName();
	int getAllignment();
	void perform();
private:
	int allignment; //1 - good, 2- bad
	string name;
};

