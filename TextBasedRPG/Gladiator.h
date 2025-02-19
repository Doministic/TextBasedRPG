#pragma once
#include"CharacterBase.h" 

class Gladiator : public CharacterBase
{
public:
	Gladiator(const std::string& name);

	void LevelUp()override;
};