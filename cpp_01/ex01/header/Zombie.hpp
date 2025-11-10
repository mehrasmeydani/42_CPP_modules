#pragma once

#include <string>

class Zombie
{
	public:
		void	announce(void);
		void	set_name(std::string name);

	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);
