#pragma once

#include "Weapon.hpp"

class HumanB
{
	public:
		void	attack();
		void	setWeapon(Weapon &weapon_type);
	private:
		std::string	name;
		Weapon		*weapon_type;
	public:
		HumanB(std::string);
		~HumanB();
};