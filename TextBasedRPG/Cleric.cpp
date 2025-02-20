#include "Cleric.h"

Cleric::Cleric(const std::string& name) 
	: CharacterBase(name, 25, 0, Attributes(5, 8, 20, 20)){}

void Cleric::LevelUp()
{
	if (level.currentLevel % 2 == 0)
	{
		attributes.luck += 5;
		attributes.speed += 5;
	}
	else if (level.currentLevel % 3 == 0)
	{
		attributes.strength += 4;
		attributes.stamina += 1;
	}
	else if (level.currentLevel % 7 == 0)
	{
		attributes.strength += 2;
		attributes.speed += 6;
		attributes.stamina += 2;
		attributes.luck += 6;
	}
	else {
		attributes.strength += 1;
		attributes.stamina += 4;
	}

	updateHealthEachLevel(0.025);
}
