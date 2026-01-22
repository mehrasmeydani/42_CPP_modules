#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		void	getStats() const;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap& operator=(const FragTrap& in);
		FragTrap(const FragTrap &in);
		~FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};