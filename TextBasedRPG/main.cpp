#include <iostream>
#include "Paladin.h"
#include "Gladiator.h"
#include "Rogue.h"
#include "Hunter.h"
#include "Warlock.h"
#include "Mage.h"
#include "Cleric.h"
#include "VooDooWitchDoctor.h"

int main()
{
	int exp = 150;

	Gladiator gladiator("Thorin");	 
	Paladin paladin("Thrain");
	Rogue rogue("Bilbo");
	Hunter hunter("Aragorn");
	Warlock warlock("Gandalf");
	Mage mage("Dumbledore");
	Cleric cleric("Ron");
	VoodooWitchDoctor voodoo("Baba");

	std::cout << "+++=============================+++\n\n";
	std::cout << "=== INITIAL STATS VoodooWitchDoctor ===\n";
	std::cout << "+++=============================+++\n";
	std::cout << "+++=============================+++\n\n";
	voodoo.DisplayStats();
	std::cout << "+++=============================+++\n";
	std::cout << "+++=============================+++\n\n";
	std::cout << "+++=============================+++\n";
	std::cout << "\nVoodooWitchDoctor Gainig XP to Level Up:\n";
	std::cout << "+++=============================+++\n\n";
	std::cout << "+++=============================+++\n";
	voodoo.GainExp(exp);
	std::cout << "+++=============================+++\n";
	std::cout << "+++=============================+++\n\n";
	std::cout << "+++=============================+++\n";
	std::cout << "=== AFTER LEVEL STATS VoodooWitchDoctor ===\n";
	std::cout << "+++=============================+++\n";
	voodoo.DisplayStats();
	std::cout << "+++=============================+++\n";

	return 0;
}