/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:12:48 by mehras            #+#    #+#             */
/*   Updated: 2026/01/21 16:47:56 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	print_error(const char *str)
{
	std::cerr << str << std::endl << "Use the following sytanx\n" << "./porgram_name <filename> <string to replace> <string replaced string>" << std::endl;
}

void	replace_str(std::ifstream &in_file, std::ofstream &outfile, const std::string &remove, const std::string &replace)
{
	ssize_t		idx = 0;
	size_t		found;
	std::string buffer;
	std::string	in_string;
	std::string out_string;

	while(std::getline(in_file, buffer))
	{
		in_string.append(buffer);
		if (!in_file.eof())
			in_string.append("\n");
	}
	idx = 0;
	while ((found = in_string.find(remove, idx)) != std::string::npos)
	{
		out_string.append(in_string.substr(idx, found - idx));
		out_string.append(replace);
		idx = found + remove.length();
	}
	out_string.append(in_string, idx);
	outfile << out_string;
}

int	main(int argc, char **argv)
{
	std::string		file_out_name;

	if (argc != 4)
		return (print_error("syntax error"), 1);
	file_out_name = argv[1];
	file_out_name.append(".replace");
	std::ifstream	in_file(argv[1]);
	if (!in_file.is_open())
		return (std::cerr << "cannot open input file" << std::endl, 1);
	std::ofstream	out_file(file_out_name.c_str());
	if (!out_file.is_open())
		return (std::cerr << "cannot open output file" << std::endl, 1);
	replace_str(in_file, out_file, argv[2], argv[3]);
	in_file.close();
	out_file.close();
	return 0;
}