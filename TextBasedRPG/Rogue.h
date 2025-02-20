#pragma once
#include "CharacterBase.h"

class Rogue : public CharacterBase 
{
public:
	Rogue(const std::string& name);

	void LevelUp() override;
};
