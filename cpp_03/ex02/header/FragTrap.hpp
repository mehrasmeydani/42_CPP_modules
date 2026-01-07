#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		void	getStats() const;

	public:
		FragTrap(std::string name);
		~FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};