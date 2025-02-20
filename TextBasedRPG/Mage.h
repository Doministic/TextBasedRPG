#pragma once
#include "CharacterBase.h"

class Mage : public CharacterBase 
{
public:
	Mage(const std::string& name);

	void LevelUp() override;
};