#pragma once
#include "CharacterBase.h"

class Hunter : public CharacterBase
{
public:
	Hunter(const std::string& name);

	void LevelUp() override;
};