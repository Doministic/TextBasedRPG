
#include <iostream>
#include <cmath>
#include "Types.h"

Health_t::Health(hp_t maxHp, hp_t armor):
				MAX_HEALTH(maxHp), armor(armor){}

void Health_t::TakeDamage(damage_t damage)
{
	if (armor > 0)
	{
		armor -= damage;
		if (armor == 0)
		{
			damage -= armor;
			currHealth -= damage;
			return;
		}
	}
	else {
		currHealth -= damage;
	}
}

void Health_t::Heal(hp_t healAmount)
{
	currHealth += healAmount;
	if (currHealth >= MAX_HEALTH)
	{
		currHealth = MAX_HEALTH;
	}
	
	std::cout << "Healed: " << healAmount << " \nCurrent Health: " << currHealth << " \nMax Health: " << MAX_HEALTH << "\n";
}

Level_t::Level(level_t level) : currentLevel(level) { expToNextLevel = CalcExpToNextLevel(); }

void Level::GainExperience(exp_t xp)
{
	if (currentLevel >= MAX_LEVEL)
	{
		currentExp = expToNextLevel;
		currentLevel = MAX_LEVEL;
		std::cout << "At MAX Level Cannot gain more experience.\n";
		return;
	}

	currentExp += xp;
	while (currentExp >= expToNextLevel && currentLevel < MAX_LEVEL)
	{
		LevelUp();
		std::cout << "Gained: " << xp << " XP. \nCurrent XP: " << currentExp << " \nXP to Next Level: " << expToNextLevel << "\n\n";
	}
}

void Level::LevelUp()
{		
	if (currentLevel >= MAX_LEVEL)
	{
		currentExp = expToNextLevel;
		currentLevel = MAX_LEVEL;
		std::cout << "MAX LEVEL REACHED\n";

		return;
	}

	currentExp -= expToNextLevel;
	currentLevel++;
	expToNextLevel = CalcExpToNextLevel();
	std::cout << "Leveled up: " << currentLevel << " / " << MAX_LEVEL << "\n";
}

exp_t Level::CalcExpToNextLevel()
{
	return static_cast<exp_t>(100 * std::pow(1.1, currentLevel - 1));
}
