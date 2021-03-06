/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Perifalk.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:36:29 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 18:17:22 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Perifalk.hpp"

void			Perifalk::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a " << CLR_BGREEN(green frog) << "!" << std::endl;
}

				Perifalk::Perifalk(std::string const &rName) :
				Victim(rName)
{
	std::cout << "Yowk yowk." << std::endl;
}

				Perifalk::Perifalk(Perifalk const &rSrc)
{
	*this = rSrc;
	std::cout << "Yowk yowk." << std::endl;
}

				Perifalk::~Perifalk(void)
{
	std::cout << "Crowk..." << std::endl;
}

Perifalk		&Perifalk::operator=(Perifalk const &rRhs)
{
	if (this != &rRhs)
	{
		_name = rRhs.getName();
	}
	return (*this);
}

				Perifalk::Perifalk(void)
{
}
