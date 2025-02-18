#include <iostream>
#include "Warrior.h"

int main()
{
	Gladiator warrior("Thorin");

	std::cout << "=== INITIAL STATS ===\n";
	warrior.DisplayStats();

	std::cout << "\nGainig XP to Level Up:\n";
	warrior.GainExp(150);

	std::cout << "=== AFTER LEVEL STATS ===\n";
	warrior.DisplayStats();

	return 0;
}