#pragma once
#include "CharacterBase.h"

class Warlock : public CharacterBase
{
public:
	Warlock(const std::string& name);

	void LevelUp() override;
};