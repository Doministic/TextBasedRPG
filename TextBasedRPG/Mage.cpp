#include "Mage.h"

Mage::Mage(const std::string& name)
	: CharacterBase(name, 25, 15, Attributes(4, 6, 15, 25)){}

void Mage::LevelUp()
{
	if (level.currentLevel % 2 == 0)
	{
		attributes.luck += 6;
		attributes.speed += 2;
	}
	else if (level.currentLevel % 3 == 0)
	{
		attributes.strength += 2;
		attributes.stamina += 2;
	}
	else if (level.currentLevel % 7 == 0)
	{
		attributes.strength += 1;
		attributes.speed += 4;
		attributes.stamina += 1;
		attributes.luck += 8;
	}
	else {
		attributes.strength += 1;
		attributes.stamina += 1;
	}

	updateHealthEachLevel(0.015);
}
