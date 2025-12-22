#include "../header/ClapTrap.hpp"

int main(void)
{
	ClapTrap clap_trap1("my_Trap");
	ClapTrap clap_trap2("your_Trap");

	clap_trap1.attack(clap_trap2.getName());
	clap_trap1.takeDamage(5);
	clap_trap1.beRepaired(3);
	clap_trap2.attack(clap_trap1.getName());
	clap_trap2.takeDamage(15);
	clap_trap1.takeDamage(10);
	clap_trap1.attack(clap_trap2.getName());
	clap_trap1.beRepaired(5);
	clap_trap1.attack(clap_trap2.getName());
	return 0;
}