#pragma once
#include "player.h"
#include <string>
class Mage : public Player
{
public:
	Mage(void);
	~Mage(void);
	int getExtraStat();
	void setExtraStat(int x);
	virtual string getName() = 0;
	virtual int getAllignment() = 0;
	virtual void perform() = 0;
protected:
	int mana;
};

