#include "../header/HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon_type) : weapon_type(weapon_type), name(name)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon_type.getType() << std::endl;
}
