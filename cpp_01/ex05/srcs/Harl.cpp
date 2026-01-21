#include "../header/Harl.hpp"
#include <iostream>

void Harl::complain(std::string level)
{
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*func_p[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int j = 0;
	for (j = 0; j < 4; j++)
		if (level == levels[j])
			break;
	switch (j)
	{
		case 0:
			(this->*func_p[0])();
			break ;
		case 1:
			(this->*func_p[1])();
			break ;
		case 2:
			(this->*func_p[2])();
			break ;
		case 3:
			(this->*func_p[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}