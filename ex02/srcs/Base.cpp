/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:10:20 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/16 09:45:07 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

// use dynamic casts here?
Base	*generate(void)
{
	std::srand(std::time(nullptr));
	int	random = std::rand();
	if (random % 7 == 2)
		return new A;
	if (random % 4 == 3)
		return new B;
	return new C;
}

Base::~Base()
{
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "Type is: A" << std::endl;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "Type is: B" << std::endl;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "Type is: C" << std::endl;
	}
}

void	identify(Base& p)
{

	try{
		A& rotta = dynamic_cast<A&>(p);
		(void) rotta;
		std::cout << "Type is: A" << std::endl;	
	}
	catch (std::exception &e)
	{
	}
	try{
		B& rotta = dynamic_cast<B&>(p);
		(void) rotta;
		std::cout << "Type is: B" << std::endl;	
	}
	catch (std::exception &e)
	{
	}
	try{
		C& rotta = dynamic_cast<C&>(p);
		(void) rotta;
		std::cout << "Type is: C" << std::endl;	
	}
	catch (std::exception &e)
	{
	}
}
