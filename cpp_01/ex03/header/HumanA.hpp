#pragma once

#include "Weapon.hpp"

class HumanA
{
	public:
		void	attack();
	private:
		Weapon		&weapon_type;
		std::string	name;
	public:
		HumanA(std::string, Weapon &weapon_type);
		~HumanA();
};