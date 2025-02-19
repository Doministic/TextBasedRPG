#pragma once

#include <iostream>
#include <string>
#include "Types.h"

class CharacterBase
{
protected:
	std::string characterName;
	Health health;
	Level level;
	Attributes attributes;
    void updateHealthEachLevel(double percent);

public:
	CharacterBase(const std::string& charName, hp_t maxHp, hp_t armor, const Attributes &initAttribs);
	virtual ~CharacterBase() {}


    damage_t GetAttack() const { return attributes.strength + attributes.stamina; }
    damage_t GetSpAttack() const { return attributes.luck + attributes.strength; }
    damage_t GetDefense() const { return attributes.stamina + attributes.strength; }
    damage_t GetSpDefense() const { return attributes.luck + attributes.speed; }
    damage_t GetDexterity() const { return attributes.speed + attributes.stamina; }
    damage_t GetFaith() const { return attributes.luck + attributes.speed; }

	void TakeDamage(damage_t damage);
	void Heal(hp_t amount);

	void GainExp(exp_t xp);
	virtual void LevelUp() = 0;
	void ProcessTurn();

    virtual void DisplayStats() const {
        std::cout << "===================================" << std::endl;
        std::cout << "Name: " << characterName << std::endl;
        std::cout << "Level: " << level.currentLevel << " (" << level.currentExp << "/" << level.expToNextLevel << " XP)" << std::endl;
        std::cout << "HP: " << health.currHealth << "/" << health.MAX_HEALTH << " (Armor: " << health.armor << ")" << std::endl;
        std::cout << "Underlying Attributes:" << std::endl;
        std::cout << "  Strength: " << attributes.strength << std::endl;
        std::cout << "  Stamina:  " << attributes.stamina << std::endl;
        std::cout << "  Luck:     " << attributes.luck << std::endl;
        std::cout << "  Speed:    " << attributes.speed << std::endl;
        std::cout << "Derived Stats:" << std::endl;
        std::cout << "  Attack:       " << GetAttack() << std::endl;
        std::cout << "  SP Attack:    " << GetSpAttack() << std::endl;
        std::cout << "  Defense:      " << GetDefense() << std::endl;
        std::cout << "  SP Defense:   " << GetSpDefense() << std::endl;
        std::cout << "  Dexterity:    " << GetDexterity() << std::endl;
        std::cout << "  Faith:        " << GetFaith() << std::endl;
        std::cout << "===================================" << std::endl;
    }
};