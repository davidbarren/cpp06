/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:13:16 by dbarrene          #+#    #+#             */
/*   Updated: 2024/09/16 10:51:07 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	{
		std::cout << "Testing identify with pointers ---------" << std::endl;
		Base *a =  new A;
		Base *b =  new B;
		Base *c =  new C;
		Base *rand = generate();
		identify(a);
		identify(b);
		identify(c);
		identify(rand);
		std::cout << "Testing identify with references ---------" << std::endl;
		identify(*a);
		identify(*b);
		identify(*c);
		identify(*rand);
		delete rand;
		delete a;
		delete b;
		delete c;
	}
}
