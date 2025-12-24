#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		void	getStats() const;

	public:
		ScavTrap(std::string name);
		~ScavTrap();
		void	attack(const std::string& target);
		void	gaurdGate();

};