#include "Warlock.h"

Warlock::Warlock(const std::string& name)
 :  CharacterBase(name, 25, 15, Attributes(6, 4, 15, 10)){}

void Warlock::LevelUp()
{
	if (level.currentLevel % 2 == 0)
	{
		attributes.luck += 2;
		attributes.speed += 6;
	}
	else if (level.currentLevel % 3 == 0)
	{
		attributes.strength += 1;
		attributes.stamina += 1;
	}
	else if (level.currentLevel % 7 == 0)
	{
		attributes.strength += 1;
		attributes.speed += 8;
		attributes.stamina += 1;
		attributes.luck += 4;
	}
	else {
		attributes.strength += 2;
		attributes.stamina += 2;
	}

	updateHealthEachLevel(0.015);
}
