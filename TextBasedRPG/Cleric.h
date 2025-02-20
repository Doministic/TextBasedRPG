#pragma once
#include "CharacterBase.h"

class Cleric : public CharacterBase
{
public:
	Cleric(const std::string& name);

	void LevelUp() override;
};