#pragma once

#include "Weapon.hpp"

class HumanB
{
	public:
		void	attack();
		void	setWeapon(Weapon &weapon_type);
	private:
		Weapon		*weapon_type;
		std::string	name;
	public:
		HumanB(std::string);
		~HumanB();
};