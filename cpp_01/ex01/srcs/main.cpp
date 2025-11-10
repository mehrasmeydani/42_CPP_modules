#include "../header/Zombie.hpp"
#include <iostream>

int	main()
{
	Zombie *zombie_horde = zombieHorde(10, "Alan");
	if (!zombie_horde)
		return (0);
	for (int i = 0; i < 10; i++)
	{
		std::cout << "No. " << i  + 1 << ": Name and occupation:\t\t" << std::flush;
		zombie_horde[i].announce();
	}
	delete [] zombie_horde;
}