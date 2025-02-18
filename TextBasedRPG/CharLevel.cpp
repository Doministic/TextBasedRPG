#include "CharacterLevel.h"
#include "Health.h"

CharLevel::CharLevel() 
{
	MAX_LEVEL = 20;
	baseLevel = 1;
	curLevel = 1;
	expToLevel = 100;
	exp = 0;
}

CharLevel::CharLevel(exp_t exp)
{
	MAX_LEVEL = 20;
	baseLevel = 1;
	curLevel = 1;
	expToLevel = 100;
	CharLevel::exp = exp;
}

level_t CharLevel::GetCharLevel() 
{
	return curLevel;
}

void CharLevel::IncreaseCharLevel()
{
	curLevel += 1;
	exp = 0;
}

exp_t CharLevel::GetCurExp()
{
	return exp;
}

exp_t CharLevel::IncreaseNeededExp(level_t curLevel, double levelMultiplier)
{
	if (curLevel == 1)
	{
		expToLevel = 100;
	} else
	{
		exp_t expToNextLevel = (exp_t)(curLevel * levelMultiplier);
		expToLevel *= expToNextLevel;
	}
	std::cout << "Exp to next Level: " << expToLevel << " and current Level is " << curLevel << "\n";
	if (curLevel == MAX_LEVEL)
	{
		return 0;
	}
	
	return expToLevel;
}

hp_t CharLevel::IncreaseCharHP(double multiplier)
{
	Health health = Health(100);
	hp_t curHealth = health.GetMaxHP();
	std::cout << "" << curHealth;
	health.SetMaxHP(curHealth + (hp_t)(curHealth * multiplier));
	curHealth = health.GetMaxHP();
	std::cout << "Max HP Increased: " << curHealth << "\n";
	return 	curHealth;
}

exp_t CharLevel::GainExp(exp_t expGained)
{
	double multiplier = (curLevel * 0.5) + ((curLevel - 1) * 0.75);
	
	do
	{
		if (expGained >= expToLevel)
		{
			exp_t curGainedExp = expGained - expToLevel;
			exp = curGainedExp;
			IncreaseCharLevel();
			IncreaseNeededExp(curLevel, multiplier);
			IncreaseCharHP(multiplier);
		}
	} while ((expGained >= expToLevel));
	
	return exp;
}


void CharLevel::DisplayLevel()
{
	std::cout << "Your Current level is: " << CharLevel::GetCharLevel() << " / " << MAX_LEVEL << "\n";
	std::cout << "Your Current Experience is: " << GetCurExp() << " and EXP needed to level is: " << expToLevel << "\n";
}