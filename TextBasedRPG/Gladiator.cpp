#include "Gladiator.h"

Gladiator::Gladiator(const std::string &name)
	: CharacterBase(name, 150, 20, Attributes(15, 10, 5, 3)) {}

void Gladiator::LevelUp()     
{
	if (level.currentLevel % 2 == 0)
	{
		attributes.strength += 3;
		attributes.speed += 1;
	}
	else if (level.currentLevel % 3 == 0)
	{
		attributes.stamina += 3;
		attributes.luck += 1;
	}
	else if (level.currentLevel % 7 == 0)
	{
		attributes.strength += 4;
		attributes.speed += 3;
		attributes.stamina += 4;
		attributes.luck += 3;
	}
	else {
		attributes.strength += 2;
		attributes.stamina += 2;
	}

	updateHealthEachLevel(0.02);
}