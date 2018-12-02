#include "StdAfx.h"
#include "Command.h"


Command::Command(CTypedPtrArray<CObArray, Player*> &players, Player *p, int numPlayerTurn)
	: players(players), p(p), numPlayerTurn(numPlayerTurn)
{
}


Command::~Command(void)
{
}

void Command::perform(){
	//players.Add(p);
}

void Command::rollback(){
	for (int i = 0; i < players.GetSize(); ++i)
		if (players[i] == p)
		{
			players.RemoveAt(i);
			return;
		}
}

