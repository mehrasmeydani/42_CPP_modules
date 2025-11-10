#include "../header/Zombie.hpp"
#include <new>
#include <iostream>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *zombie_horde = new (std::nothrow) Zombie[N];
	if (!zombie_horde)
	{
		std::cerr << "heap allocation failed in newZombie!" << std::endl;
		return (zombie_horde);
	}
	for (int i = 0; i < N; i++)
	{
		zombie_horde[i].set_name(name);
	}
	return (zombie_horde);
}
