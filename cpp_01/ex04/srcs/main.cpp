/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:12:48 by mehras            #+#    #+#             */
/*   Updated: 2025/11/28 00:34:22 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	print_error(const char *str)
{
	std::cerr << str << std::endl << "Use the following sytanx\n" << "./porgram_name <filename> <string to replace> <string replaced string>" << std::endl;
}

char	check_for_nl(std::ifstream &in_file)
{
	char	last;
	in_file.clear();
	in_file.seekg(-1, std::ios::end);
	in_file.get(last);
	in_file.clear();
	in_file.seekg(0, std::ios::beg);
	return last;
}


void	replace_str(std::ifstream &in_file, std::ofstream &outfile, const std::string &remove, const std::string &replace)
{
	ssize_t		idx = 0;
	size_t		found;
	bool		first = 0;
	std::string	in_string;
	std::string out_string;
	std::string prev_string;
	char		last = check_for_nl(in_file);

	while (1)
	{
		if (std::getline(in_file, in_string))
		{
			idx = 0;
			if (first)
				outfile << std::endl;
			else
				first = 1;
			while ((found = in_string.find(remove, idx)) != std::string::npos)
			{
				out_string = in_string.substr(idx, found - idx);
				outfile << out_string;
				outfile << replace;
				idx = found + remove.length();
			}
			outfile << in_string.substr(idx, in_string.length() - idx);
			prev_string = in_string;
		}
		else
		{
			if (last == '\n')
				outfile << std::endl;
			break ;
		}
	}
	
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