#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		void	getStats() const;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap& in);
		ScavTrap(const ScavTrap &in);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};