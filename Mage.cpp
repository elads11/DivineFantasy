#include "StdAfx.h"
#include "Mage.h"


Mage::Mage(void) 
{
	setExtraStat(0);
}


Mage::~Mage(void)
{
}

int Mage::getExtraStat(){ return mana; }
void Mage::setExtraStat(int x){ mana = x; }
