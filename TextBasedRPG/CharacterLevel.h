#pragma once
#include "Types.h"

class CharLevel
{
private:
	level_t MAX_LEVEL; // Max Level for characters to reach
	level_t baseLevel = 1; // Level a character starts at no matter what 
	level_t curLevel = baseLevel;
	exp_t exp = 0; // Current EXP a character has, will always start at 0 in each level
	exp_t expToLevel = 100;	// Exp needed to level up

public:
	CharLevel();
	CharLevel(exp_t exp);

	level_t GetCharLevel();
	void IncreaseCharLevel();

	exp_t GetCurExp();
	exp_t GetExpToNextLevel(level_t curLevel, double multiplier);
	exp_t IncreaseNeededExp(level_t curLevel, double levelMultiplier);
	exp_t GainExp(exp_t expGain);
	hp_t IncreaseCharHP(double multiplier);

	void DisplayLevel();
};