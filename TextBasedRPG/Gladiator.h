#pragma once
#include"CharacterBase.h" 

class Gladiator : public CharacterBase
{
public:
	Gladiator(const std::string& name) : CharacterBase(name, 150, 20, Attributes(15, 10, 5, 3)) {}

	void LevelUp()override;
};