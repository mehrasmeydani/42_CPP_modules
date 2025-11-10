#include "../header/Zombie.hpp"
#include <iostream>
#include <new>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "I was: " << this->name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie	*newZombie(std::string name)
{
	Zombie *new_zombie = new (std::nothrow)Zombie;
	if (!new_zombie)
	{
		std::cerr << "heap allocation failed in newZombie!" << std::endl;
		return (new_zombie);
	}
	new_zombie->set_name(name);
	return (new_zombie);
}

void randomChump(std::string name)
{
	Zombie random_chump;
	random_chump.set_name(name);
	random_chump.announce();
}
