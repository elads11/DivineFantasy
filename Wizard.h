#pragma once
#include "mage.h"
class Wizard : public Mage
{
public:
	Wizard(void);
	~Wizard(void);
	string getName();
	int getAllignment();
	void perform();
private:
	int allignment; //1 - good, 2- bad
	string name;
};

