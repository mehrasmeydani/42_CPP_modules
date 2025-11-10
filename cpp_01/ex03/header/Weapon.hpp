#pragma once

#include <string>

class Weapon
{
	public:
		const std::string&	getType();
		void				setType(std::string type);
	private:
		std::string	type;
	public:
		Weapon(std::string type);
		~Weapon();
};
