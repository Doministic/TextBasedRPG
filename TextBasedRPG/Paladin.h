#pragma once
#include "CharacterBase.h"

class Paladin : public CharacterBase 
{
public: 
	Paladin(const std::string& name);

	void LevelUp() override;
};