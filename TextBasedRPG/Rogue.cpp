#include "Rogue.h"

Rogue::Rogue(const std::string& name)
	: CharacterBase(name, 75, 15, Attributes(10, 8, 15, 7)){}

void Rogue::LevelUp()
{
	if (level.currentLevel % 2 == 0)
	{
		attributes.luck += 3;
		attributes.speed += 5;
	}
	else if (level.currentLevel % 3 == 0)
	{
		attributes.strength += 1;
		attributes.stamina += 1;
	}
	else if (level.currentLevel % 7 == 0)
	{
		attributes.strength += 2;
		attributes.speed += 6;
		attributes.stamina += 3;
		attributes.luck += 5;
	}
	else {
		attributes.strength += 2;
		attributes.stamina += 2;
	}

	updateHealthEachLevel(0.01);
}
