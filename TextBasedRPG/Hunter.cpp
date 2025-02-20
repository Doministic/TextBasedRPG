#include "Hunter.h"

Hunter::Hunter(const std::string& name)
	: CharacterBase(name, 75, 15, Attributes(8, 10, 7, 15)){}

void Hunter::LevelUp()
{
	if (level.currentLevel % 2 == 0)
	{
		attributes.luck += 5;
		attributes.speed += 3;
	}
	else if (level.currentLevel % 3 == 0)
	{
		attributes.strength += 1;
		attributes.stamina += 1;
	}
	else if (level.currentLevel % 7 == 0)
	{
		attributes.strength += 3;
		attributes.speed += 5;
		attributes.stamina += 2;
		attributes.luck += 3;
	}
	else {
		attributes.strength += 2;
		attributes.stamina += 2;
	}

	updateHealthEachLevel(0.01);
}
