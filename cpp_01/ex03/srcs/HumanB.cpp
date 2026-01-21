#include "../header/HumanB.hpp"
#include <iostream>
HumanB::HumanB(std::string name) : name(name) , weapon_type(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (!weapon_type)
	{
		std::cout << name << " does not have a weapon to attack!\n";
		return ;
	}
	std::cout << name << " attacks with their " << weapon_type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon_type)
{
	this->weapon_type = &weapon_type;
}
