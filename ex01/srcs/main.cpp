/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:39:10 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/12 15:06:43 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{

	Data mystruct;
	Data *ptr = Serializer::deserialize(Serializer::serialize(&mystruct));

	std::cout << (ptr == &mystruct) << std::endl;



}
