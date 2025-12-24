#include "../header/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	std::cout << "ScavTrap " << name << " constructed." <<  std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->EP == 0)
	{
		std::cout << "ScavTrap " << this->Name << " has no energy to attack!" << std::endl;
		return ;
	}
	else if (this->HP == 0)
	{
		std::cout << "ScavTrap " << this->Name << " is dead!" << std::endl;
		return ;
	}
	else
	{
		this->EP--;
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AD << " points of damage!" << std::endl;
	}
	this->getStats();
}

void ScavTrap::getStats() const
{
	std::cout << "ScavTrap " << this->Name << " Stats -- HP: " << this->HP << ", EP: " << this->EP << ", AD: " << this->AD << std::endl;
}

void ScavTrap::gaurdGate()
{
	if (this->HP == 0)
	{
		std::cout << "ScavTrap " << this->Name << " is dead!" << std::endl;
		return ;
	}
	else if (this->EP == 0)
	{
		std::cout << "ScavTrap " << this->Name << " has no energy to enter Gate keeper mode." << std::endl;
		return ;
	}
	else
	{
		this->EP--;
		std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode." << std::endl;
	}
	this->getStats();
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " destructed." <<  std::endl;
}