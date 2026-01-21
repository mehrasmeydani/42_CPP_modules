#include "../header/Zombie.hpp"
#include <new>
#include <iostream>

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
