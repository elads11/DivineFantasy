#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player : public CObject
{
public:
	DECLARE_SERIAL(Player)
	Player();
	~Player(void);
	
	//location functions - for draw
	int getSize() const;
	int getPosX() const;
	int getPosY() const;
	void setPosX(int pos);
	void setPosY(int pos);

	//base player stats
	int artefacts[3]; //3 artefacts required to win the game, first 2 to get the 3rd
	
	int getHP() const;
	int getGold() const;
	int getMonstersKilled() const;

	void setHP(int x);
	void setGold(int x);
	void setMonstersKilled(int x);
	
	//virtual functions - the subclasses implement their own functions as they see fit - the extra stat, the player, allignment and the special skill
	virtual string getName();
	virtual int getAllignment(); 
	virtual void perform(); // character can perform his special skill if he meets certain conditions
	virtual int getExtraStat(); //each character type must implement its own extra stat. Warrior: WillPower, Mage: Mana
	virtual void setExtraStat(int x); //updates the extra stat

	void Serialize(CArchive& archive);

	void Draw(CDC* dc, int numPlayer);
	int loc;
	int level;
	int player_type; //determine which character the player is playing

protected:
	int hp; 
	int gold;
	int monstersKilled;
	int size;
	int posX, posY;
	
};

