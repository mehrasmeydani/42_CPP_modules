#include "../header/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	this->Name = "default";
	this->HP = 10;
	this->EP = 10;
	this->AD = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
Name(name), HP(10), EP(10), AD(0)
{
	std::cout << "ClapTrap " << name << " constructed." <<  std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& in)
{
	this->Name = in.getName();
	this->AD = in.AD;
	this->EP = in.EP;
	this->HP = in.HP;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &in)
{
	*this = in;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->EP == 0)
	{
		std::cout << "ClapTrap " << this->Name << " has no energy to attack!" << std::endl;
		return ;
	}
	if (this->HP == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead!" << std::endl;
		return ;
	}
	this->EP--;
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AD << " points of damage!" << std::endl;
	this->getStats();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EP == 0)
		std::cout << "ClapTrap " << this->Name << " has no energy to repair!" << std::endl;
	else
	{
		this->EP--;
		this->HP += amount;
		std::cout << "ClapTrap " << this->Name << " is repaired for " << amount << " points of health!" << std::endl;
	}
	this->getStats();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HP == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead!" << std::endl;
	}
	else if (this->HP <= amount)
	{
		std::cout << "ClapTrap " << this->Name << " takes " << this->HP << " points of damage!" << std::endl;
		this->HP = 0;
	}
	else
	{
		this->HP -= amount;
		std::cout << "ClapTrap " << this->Name << " takes " << amount << " points of damage!" << std::endl;
	}
	this->getStats();
}

void	ClapTrap::getStats() const
{
	std::cout << "ClapTrap " << this->Name << " Stats -- HP: " << this->HP << ", EP: " << this->EP << ", AD: " << this->AD << std::endl;
}

const std::string&	ClapTrap::getName() const
{
	return (this->Name);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->getName() << " destructed." <<  std::endl;
}
