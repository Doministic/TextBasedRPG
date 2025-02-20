#include "VooDooWitchDoctor.h"

VoodooWitchDoctor::VoodooWitchDoctor(const std::string& name)
	: CharacterBase(name, 25, 0, Attributes(8, 5, 20, 20)) {}

void VoodooWitchDoctor::LevelUp()
{
	if (level.currentLevel % 2 == 0)
	{
		attributes.luck += 5;
		attributes.speed += 5;
	}
	else if (level.currentLevel % 3 == 0)
	{
		attributes.strength += 1;
		attributes.stamina += 4;
	}
	else if (level.currentLevel % 7 == 0)
	{
		attributes.strength += 2;
		attributes.speed += 6;
		attributes.stamina += 2;
		attributes.luck += 6;
	}
	else {
		attributes.strength += 4;
		attributes.stamina += 1;
	}

	updateHealthEachLevel(0.025);
}
