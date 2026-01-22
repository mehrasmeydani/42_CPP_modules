#pragma once

#include <string>

class   ClapTrap
{
	private:
		void	getStats() const;

	protected:
		std::string     Name;
		unsigned int	HP;
		unsigned int	EP;
		unsigned int	AD;

	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		const std::string&	getName() const;
		ClapTrap& operator=(const ClapTrap& in);
		ClapTrap(const ClapTrap &in);
		ClapTrap(std::string name);
		ClapTrap();
		~ClapTrap();
};