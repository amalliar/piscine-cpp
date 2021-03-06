/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 04:08:54 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/01 17:17:19 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int			Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

			Fixed::Fixed(void) :
			_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

			Fixed::Fixed(Fixed const &rSrc) :
			_value(rSrc._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

			Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed		&Fixed::operator=(Fixed const &rRhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rRhs)
	{
		_value = rRhs._value;
	}
	return (*this);
}
