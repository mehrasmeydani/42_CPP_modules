#include "../header/Zombie.hpp"

int main()
{
	Zombie *heap_zombie;
	Zombie stack_zombie;

	heap_zombie = newZombie("Alan");
	if (!heap_zombie)
		return (0);
	stack_zombie.set_name("Alien");
	heap_zombie->announce();
	stack_zombie.announce();
	delete heap_zombie;
}