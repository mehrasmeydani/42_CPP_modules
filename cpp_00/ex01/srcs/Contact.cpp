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
	std::cout << "|";
	if (this->first_name.length() > 10)
		std::cout << std::right << std::setw(9) << this->first_name.substr(0, 9) << ".";
	else
		std::cout << std::right << std::setw(10) << this->first_name;
	std::cout << "|";
	if (this->last_name.length() > 10)
		std::cout << std::right << std::setw(9) << this->last_name.substr(0, 9) << ".";
	else
		std::cout << std::right << std::setw(10) << this->last_name;
	std::cout << "|";
	if (this->nickname.length() > 10)
		std::cout << std::right << std::setw(9) << this->nickname.substr(0, 9) << ".";
	else
		std::cout << std::right << std::setw(10) << this->nickname;
	std::cout << std::endl;
}

void	Contact::set_conact(void)
{
	std::string	buffer;
	std::cout << "ENTER FIRST NAME: " << std::flush;
	while (buffer.empty())
		std::getline(std::cin, buffer);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	this->first_name = buffer;
	buffer.clear();
	std::cout << "ENTER LAST NAME: " << std::flush;
	while (buffer.empty())
		std::getline(std::cin, buffer);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	this->last_name = buffer;
	buffer.clear();
	std::cout << "ENTER NICKNAME: " << std::flush;
	while (buffer.empty())
		std::getline(std::cin, buffer);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	this->nickname = buffer;
	buffer.clear();
	std::cout << "ENTER PHONE NUMBER: " << std::flush;
	while (buffer.empty())
		std::getline(std::cin, buffer);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	this->phone_number = buffer;
	buffer.clear();
	std::cout << "ENTER DARKEST SECRET: " << std::flush;
	while (buffer.empty())
		std::getline(std::cin, buffer);
	if (std::cin.eof())
		return ((void)(this->exit = 1));
	this->darkest_secret = buffer;
	return ;
}

void	Contact::get_conact_2(void)
{
	std::cout << "FIRST NAME: " << this->first_name << std::endl;
	std::cout << "LAST NAME: " << this->last_name <<  std::endl;
	std::cout << "NICKNAME: " << this->nickname << std::endl;
	std::cout << "PHONE NUMBER: " << this->phone_number << std::endl;
	std::cout << "DARKEST SECRET: " << this->darkest_secret << std::endl;
}
