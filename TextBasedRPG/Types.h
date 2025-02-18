#pragma once
#include <cstdint>

typedef uint16_t hp_t;
typedef uint16_t damage_t;
typedef uint16_t level_t;
typedef uint16_t attrib_t;
typedef uint32_t exp_t;

typedef struct Health {
	hp_t MAX_HEALTH;
	hp_t currHealth = MAX_HEALTH;
	hp_t armor;

	Health(hp_t maxHP, hp_t armor);

	void TakeDamage(hp_t damage);
	void Heal(hp_t amount);
} Health_t;

typedef struct Level {
	static const level_t MAX_LEVEL = 20;
	level_t currentLevel;
	exp_t currentExp = 0;
	exp_t expToNextLevel;

	Level(level_t curLevel = 1);

	void GainExperience(exp_t xp);
	void LevelUp();
	exp_t CalcExpToNextLevel();
} Level_t;

typedef struct Attributes {
	attrib_t strength;
	attrib_t stamina;
	attrib_t speed;
	attrib_t luck;

	Attributes(attrib_t str = 0, attrib_t sta = 0, attrib_t spd = 0, attrib_t lck = 0) : strength(str), stamina(sta), speed(spd), luck(lck) {}
} Attributes_t;

