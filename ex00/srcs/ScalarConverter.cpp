/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:32:34 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/21 14:38:51 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

typedef enum e_types
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	NONE = 4,
}	t_types;


static bool	uniform_digits(std::string str)
{
	for (char &c : str)
	{
		if (!std::isdigit(str.back()) && str.back() != 'f' && !std::isdigit(str[c]))
			return false;
	}
	return true;
}

static int find_type(std::string str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR;
	if (str == "-inff" || str== "inff")
		return FLOAT;
	if (str == "-inf" || str== "inf" || str == "nan")
		return DOUBLE;
	if (str.find('.') != SIZE_MAX && str[str.find('.') + 1] && !uniform_digits(&str[str.find('.') + 1]))
		return NONE;
	try
	{
		long res = std::stol(str);
		if (res > INT_MAX || res < INT_MIN)
			return NONE;
	}
	catch (std::exception &e)
	{
		return NONE;
	}
	if (std::isalpha(str[0]) && (str.find("inff") == SIZE_MAX) && str.length() == 1)
		return CHAR;
	else if ((str.back() == 'f' && str.find('.') != SIZE_MAX))
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
		std::cout << static_cast<float>(str[0]);
		std::cout <<"f" << std::endl;
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
		std::cout << static_cast<float>(result);
		std::cout <<"f" << std::endl;
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
		if (result > 126 || result < 33 || str == "-inff" || str == "inff"
				|| str == "nan" || str == "inf" || str == "-inf")
			std::cout << "impossible" << std::endl;
		else
		std::cout << static_cast<char>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	if (str == "nan" || str == "inff" || str == "-inff")
		std::cout << "impossible" << std::endl;
	else
	{
		try
		{
			std::cout << static_cast<int>(result) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "impossible" << std::endl;
		}
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
		if (result > 126 || result < 33 || str == "-inff" || str == "inff"
				|| str == "nan" || str == "inf" || str == "-inf")
			std::cout << "impossible" << std::endl;
		else
		std::cout << static_cast<char>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	if (str == "nan" || str == "inf" || str == "-inf")
		std::cout << "impossible" << std::endl;
	else
	{
		try
		{
			std::cout << static_cast<int>(result) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "impossible" << std::endl;
		}
	}
	std::cout << "float: ";
	try
	{
		std::cout << static_cast<float>(result);
		std::cout <<"f" << std::endl;
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
void	ScalarConverter::convert(std::string type)
{
	void (*ptr[5])(std::string) = {&from_char, &from_int, &from_float, &from_double, &none_error};
	ptr[find_type(type)](type);
}
