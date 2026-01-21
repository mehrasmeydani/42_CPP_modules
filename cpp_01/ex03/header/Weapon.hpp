#pragma once

#include <string>

class Weapon
{
	public:
		const std::string&	getType();
		void				setType(const std::string &type);
	private:
		std::string	type;
	public:
		Weapon(const std::string &type);
		~Weapon();
};
