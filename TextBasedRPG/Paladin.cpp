#include "Paladin.h"

Paladin::Paladin(const std::string& name) 
	: CharacterBase(name, 150, 20, Attributes(12, 13, 4, 4)) {}

void Paladin::LevelUp()
{
	if (level.currentLevel % 2 == 0)
	{
		attributes.stamina += 2;
		attributes.speed += 2;
	}
	else if (level.currentLevel % 3 == 0)
	{
		attributes.strength += 3;
		attributes.luck += 1;
	}
	else if (level.currentLevel % 7 == 0)
	{
		attributes.strength += 3;
		attributes.speed += 4;
		attributes.stamina += 3;
		attributes.luck += 4;
	}
	else {
		attributes.strength += 1;
		attributes.stamina += 3;
	}

	updateHealthEachLevel(0.02);
}
