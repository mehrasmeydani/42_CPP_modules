#pragma once
#include <string>
#include <iostream>

class   ClapTrap
{
	private:
		std::string     Name;
		unsigned int	HP;
		unsigned int	EP;
		unsigned int	AD;

	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		const std::string&	getName() const;
		void	getStats() const;
		ClapTrap(std::string name);
		~ClapTrap();
};