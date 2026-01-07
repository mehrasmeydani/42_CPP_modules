#include "../header/ClapTrap.hpp"
#include "../header/ScavTrap.hpp"

int main() {
	std::cout << "___creating___" << std::endl;
	ClapTrap robot("Clap");
	std::cout << std::endl;
	ScavTrap derived("Scav");

	std::cout << "\n___testing ClapTrap___" << std::endl;
	robot.attack("A");
	robot.takeDamage(3);
	robot.beRepaired(5);
	robot.attack("B");
	robot.takeDamage(12);
	robot.beRepaired(3);

	std::cout << "\n___testing ScavTrap___" << std::endl;
	derived.attack("A");
	derived.takeDamage(9);
	derived.beRepaired(5);
	derived.guardGate();
	derived.attack("B");
	derived.takeDamage(90);
	derived.beRepaired(3);

	std::cout << "\n___testing ScavTrap 1___" << std::endl;
	ScavTrap derived1 = derived;
	derived1.attack("A");
	derived1.takeDamage(3);
	derived1.beRepaired(5);
	derived1.guardGate();
	derived1.attack("B");
	derived1.takeDamage(12);
	derived1.beRepaired(3);

	std::cout << "\n___testing ScavTrap 2___" << std::endl;
	ScavTrap derived2(derived);
	derived2.attack("A");
	derived2.takeDamage(9);
	derived2.beRepaired(5);
	derived2.guardGate();
	derived2.attack("B");
	derived2.takeDamage(30);
	derived2.beRepaired(3);

	std::cout << "\n___deleting___" << std::endl;
	return 0;
}