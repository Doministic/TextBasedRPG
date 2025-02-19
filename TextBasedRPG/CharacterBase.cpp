#include <iostream>
#include "CharacterBase.h"

CharacterBase::CharacterBase(const std::string& charName, hp_t maxHp, hp_t armor, const Attributes & initAttribs) :
	characterName(charName), health(maxHp, armor), level(1), attributes(initAttribs) {}



void CharacterBase::TakeDamage(damage_t damage)
{
	health.TakeDamage(damage);
}


void CharacterBase::Heal(hp_t amount)
{
	health.Heal(amount);
}

void CharacterBase::GainExp(exp_t exp)
{
	level.currentExp += exp;

	level.GainExperience(exp);

	while (level.currentExp >= level.expToNextLevel && level.currentLevel <= level.MAX_LEVEL)
	{
		level.currentExp -= level.expToNextLevel;
		LevelUp();
		level.expToNextLevel = level.CalcExpToNextLevel();
	}
}

void CharacterBase::updateHealthEachLevel(double percent)
{
	hp_t multiplier = static_cast<hp_t>(level.currentLevel * ((attributes.luck + attributes.stamina) * percent) + level.currentLevel *((attributes.strength * attributes.speed) * percent));
	std::cout << "\n\nHealth is increasing by: " << multiplier << "\n\n";
	health.MAX_HEALTH = (health.currHealth + multiplier);
	health.currHealth = health.MAX_HEALTH;
}

void CharacterBase::ProcessTurn()
{
	// TODO: Add logic for a character to process turn affects. 
}
