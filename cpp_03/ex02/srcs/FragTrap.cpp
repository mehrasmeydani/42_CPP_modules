#include "../header/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("default")
{
	this->HP = 100;
	this->EP = 100;
	this->AD = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->HP = 100;
	this->EP = 100;
	this->AD = 30;
	std::cout << "FragTrap " << name << " constructed." <<  std::endl;
}

FragTrap::FragTrap(const FragTrap& in) : ClapTrap(in.getName())
{
	this->AD = in.AD;
	this->HP = in.HP;
	this->EP = in.EP;
}

FragTrap& FragTrap::operator=(const FragTrap &in)
{
	this->Name = in.getName();
	this->AD = in.AD;
	this->HP = in.HP;
	this->EP = in.EP;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->EP == 0)
	{
		std::cout << "FragTrap " << this->Name << " has no energy to attack!" << std::endl;
		return ;
	}
	else if (this->HP == 0)
	{
		std::cout << "FragTrap " << this->Name << " is dead!" << std::endl;
		return ;
	}
	else
	{
		this->EP--;
		std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->AD << " points of damage!" << std::endl;
	}
	this->getStats();
}

void FragTrap::getStats() const
{
	std::cout << "FragTrap " << this->Name << " Stats -- HP: " << this->HP << ", EP: " << this->EP << ", AD: " << this->AD << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->HP == 0)
	{
		std::cout << "FragTrap " << this->Name << " is dead!" << std::endl;
		return ;
	}
	else if (this->EP == 0)
	{
		std::cout << "FragTrap " << this->Name << " has no energy to enter Gate keeper mode." << std::endl;
		return ;
	}
	else
	{
		this->EP--;
		std::cout << "FragTrap " << this->Name << " wants a really big high five" << std::endl;
	}
	this->getStats();
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " destructed." <<  std::endl;
}