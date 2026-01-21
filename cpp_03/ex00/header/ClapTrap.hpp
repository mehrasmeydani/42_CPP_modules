#pragma once
#include <string>

class   ClapTrap
{
	private:
		std::string     Name;
		unsigned int	HP;
		unsigned int	EP;
		unsigned int	AD;
		void	getStats() const;

	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		const std::string&	getName() const;
		ClapTrap& operator=(const ClapTrap& in);
		ClapTrap(const ClapTrap &in);
		ClapTrap(std::string name);
		~ClapTrap();
};