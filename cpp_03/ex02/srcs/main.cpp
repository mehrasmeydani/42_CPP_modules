#include "../header/ClapTrap.hpp"
#include "../header/ScavTrap.hpp"
#include "../header/FragTrap.hpp"

int main() {
	std::cout << "\n_________TESTS_________" << std::endl;

	std::cout << "\n_________Construction_________" << std::endl;
	ClapTrap robot("ccc");
	std::cout << std::endl;
	ScavTrap scav("sss");
	std::cout << std::endl;
	FragTrap frag("fff");

	std::cout << "\n_________Testing ClapTrap_________" << std::endl;
	robot.attack("A");
	robot.takeDamage(10);
	robot.beRepaired(5);
	robot.attack("B");
	robot.takeDamage(300);
	robot.beRepaired(5);

	std::cout << "\n_________Testing ScavTrap_________" << std::endl;
	scav.attack("A");
	scav.takeDamage(1);
	scav.beRepaired(100);
	scav.guardGate();
	scav.attack("B");
	scav.takeDamage(15);
	scav.beRepaired(12);

	std::cout << "\n_________Testing ScavTrap 1_________" << std::endl;
	ScavTrap scav1 = ScavTrap("SSS");
	scav1.attack("A");
	scav1.takeDamage(1);
	scav1.beRepaired(100);
	scav1.guardGate();
	scav1.attack("B");
	scav1.takeDamage(15);
	scav1.beRepaired(12);

	std::cout << "\n_________Testing ScavTrap 2_________" << std::endl;
	ScavTrap scav2 = scav;
	scav2.attack("A");
	scav2.takeDamage(1);
	scav2.beRepaired(100);
	scav2.guardGate();
	scav2.attack("B");
	scav2.takeDamage(15);
	scav2.beRepaired(12);
	
	std::cout << "\n_________Testing FragTrap_________" << std::endl;
	frag.attack("A");
	frag.takeDamage(1);
	frag.beRepaired(3);
	frag.highFivesGuys();
	frag.attack("B");
	frag.takeDamage(12);
	frag.beRepaired(3);

	std::cout << "\n_________Testing FragTrap 1_________" << std::endl;
	FragTrap frag1 = FragTrap("FFF");
	frag1.attack("A");
	frag1.takeDamage(1);
	frag1.beRepaired(3);
	frag1.highFivesGuys();
	frag1.attack("B");
	frag1.takeDamage(12);
	frag1.beRepaired(3);

	std::cout << "\n_________Testing FragTrap 2_________" << std::endl;
	FragTrap frag2 = frag;
	frag2.attack("A");
	frag2.takeDamage(1);
	frag2.beRepaired(3);
	frag2.highFivesGuys();
	frag2.attack("B");
	frag2.takeDamage(12);
	frag2.beRepaired(3);

	std::cout << "\n_________Destruction_________" << std::endl;
    return 0;
}