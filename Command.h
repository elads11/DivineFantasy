#pragma once
#include "Player.h"

class Command
{
public:
	Command(CTypedPtrArray<CObArray, Player*> &players, Player *p, int numPlayerTurn);
	~Command(void);
	
	void perform();
	void rollback();
	
	CTypedPtrArray<CObArray, Player*> &players;
	Player *p;
	int numPlayerTurn;
};

