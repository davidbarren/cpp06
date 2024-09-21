/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:31:43 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/16 12:15:33 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funcs.hpp"


static int find_type(std::string str)
{
	if (std::isalpha(str[0]))
		return CHAR;
	else if (str.find('.') && str.back() == 'f')
		return FLOAT;
	else if (str.find('.') && std::isdigit(str[0]))
		return DOUBLE;
	else 
		return INT;
}
