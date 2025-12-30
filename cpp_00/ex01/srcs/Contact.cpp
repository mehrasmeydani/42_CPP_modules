#include "../header/Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
	this->exit = 0;
}

Contact::~Contact(void)
{
}

void	Contact::get_conact(void)
{
	std::cout << "|" << std::left << std::setw(10) << this->first_name << "|" << std::left << std::setw(10) << this->last_name << "|" << std::left << std::setw(10) << this->last_name << std::endl;
}

void	Contact::set_conact(void)
{
	std::cout << "ENTER FIRST NAME: " << std::flush;
	std::getline(std::cin, this->first_name);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	std::cout << "ENTER LAST NAME: " << std::flush;
	std::getline(std::cin, this->last_name);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	std::cout << "ENTER NICKNAME: " << std::flush;
	std::getline(std::cin, this->nickname);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	std::cout << "ENTER PHONE NUMBER: " << std::flush;
	std::getline(std::cin, this->phone_number);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	std::cout << "ENTER DARKEST SECRET: " << std::flush;
	std::getline(std::cin, this->darkest_secret);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	return ;
}
