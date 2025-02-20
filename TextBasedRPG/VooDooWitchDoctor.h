#pragma once
#include "CharacterBase.h"

class VoodooWitchDoctor : public CharacterBase
{
public:
	VoodooWitchDoctor(const std::string& name);

	void LevelUp() override;
};
