#pragma once
#include "player.h"
#include <string>
class Warrior : public Player
{
public:
	Warrior(void);
	~Warrior(void);
	int getExtraStat();
	void setExtraStat(int x);
	virtual string getName() = 0;
	virtual int getAllignment() = 0;
	virtual void perform() = 0;
protected:
	int willPower;
};

