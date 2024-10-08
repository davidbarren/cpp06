/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:32:52 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/21 14:56:37 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"
int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please input a string representation of ONE C++ literal" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}
