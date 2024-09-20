/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:32:52 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/20 16:56:23 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"
#include "Funcs.hpp"

typedef enum e_types
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	NONE = 4,
}	t_types;

static int find_type(std::string str)
{
	if (std::isalpha(str[0]) && (str.find("inff") == SIZE_MAX) && str.length() == 1)
		return CHAR;
	else if ((str.back() == 'f') || (str.find("inff") != SIZE_MAX))
		return FLOAT;
	else if (str.find('.') != SIZE_MAX) 
		return DOUBLE;
	else if (!std::isalpha(str[0]))
		return INT;
	return NONE;
}

static	void	from_char(std::string str)
{
	std::cout << "char: " << str[0] << std::endl;
	std::cout << "int: ";
	try
	{
		std::cout << static_cast<int>(str[0]) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		std::cout << static_cast<float>(str[0]) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		std::cout << static_cast<double>(str[0]) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

static	void	from_int(std::string str)
{
	int result = std::stoi(str);
	std::cout << "int: " << result << std::endl;;
	std::cout << "char: ";
	try
	{
		if (result > 126 || result < 33)
			std::cout << "impossible" << std::endl;
		else
		std::cout << static_cast<char>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		std::cout << static_cast<float>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		std::cout << static_cast<double>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

static	void	from_float(std::string str)
{
	float result = std::stof(str);
	std::cout << "float: " << result << std::endl;
	std::cout << "char: ";
	try
	{
		if (result > 126 || result < 33)
			std::cout << "impossible" << std::endl;
		else
		std::cout << static_cast<char>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		std::cout << static_cast<int>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		std::cout << static_cast<double>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

static	void	from_double(std::string str)
{
	double result = std::stod(str);
	std::cout << "double: " << result << std::endl;;
	std::cout << "char: ";
	try
	{
		if (result > 126 || result < 33)
			std::cout << "impossible" << std::endl;
		else
		std::cout << static_cast<char>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		std::cout << static_cast<int>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		std::cout << static_cast<float>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

static void	none_error(std::string str)
{
	std::cout << str << " is not a primitive type, please try again :)" << std::endl;
}

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please input a string representation of ONE C++ literal" << std::endl;
		return 1;
	}
	void (*ptr[5])(std::string) = {&from_char, &from_int, &from_float, &from_double, &none_error};
	std::string arg = argv[1];
	ptr[find_type(arg)](arg);
}
