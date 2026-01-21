#include "../header/Zombie.hpp"

void randomChump(std::string name)
{
	Zombie random_chump;
	random_chump.set_name(name);
	random_chump.announce();
}