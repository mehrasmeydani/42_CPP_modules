#include "../header/HumanB.hpp"
#include <iostream>
HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon_type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon_type)
{
	this->weapon_type = &weapon_type;
}
