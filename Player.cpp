#include "StdAfx.h"
#include "Player.h"
using namespace std;
#include <string>

#define SIZE 36

IMPLEMENT_SERIAL(Player, CObject, 1)
Player::Player() : gold(0), hp(5), monstersKilled(0)
{
	for (int i=0; i<3; i++) 
		artefacts[i] = 0;
}

Player::~Player(void){ }

int Player::getSize() const{ return size; }
int Player::getPosX() const{ return posX; }
int Player::getPosY() const{ return posY; }

void Player::setPosX(int pos){ posX = pos; }
void Player::setPosY(int pos){ posY = pos; }

void Player::perform() {}

string Player::getName() { return ""; }

int Player::getAllignment() {return 0;}

int Player::getExtraStat() {return 0;}

void Player::setExtraStat(int x) {}

int Player::getHP() const{ return hp; }
int Player::getGold() const{ return gold; }
int Player::getMonstersKilled() const{ return monstersKilled; }

void Player::setHP(int x){ hp = x; }
void Player::setGold(int x){ gold = x; }
void Player::setMonstersKilled(int x){ monstersKilled = x; }

void Player::Draw(CDC *dc, int numPlayer) {
	if (numPlayer == 1){
		CBrush brush(RGB(47,75,213));
		CBrush * old = dc->SelectObject(&brush);
		dc->Ellipse(posX,posY,posX+SIZE,posY+SIZE);
		dc->SelectObject(old);
	}
	if (numPlayer == 2){
		CBrush brush(RGB(51,229,75));
		CBrush * old = dc->SelectObject(&brush);
		dc->Ellipse(posX,posY+SIZE,posX+SIZE,posY+SIZE+SIZE);
		dc->SelectObject(old);		
	}
}

void Player::Serialize(CArchive& archive){
	CObject::Serialize( archive );
	if(archive.IsStoring())
		archive << posX << posY << loc << level << hp << gold << monstersKilled << artefacts[0] << artefacts[1] << artefacts[2] << player_type;
	else
        archive >> posX >> posY >> loc >> level >> hp >> gold >> monstersKilled >> artefacts[0] >> artefacts[1] >> artefacts[2] >> player_type;
		
}