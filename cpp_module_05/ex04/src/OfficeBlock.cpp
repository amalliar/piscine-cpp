/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:36:51 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/24 22:45:28 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

void			OfficeBlock::setIntern(Intern const &rIntern)
{
	this->_pIntern = &rIntern;
}

void			OfficeBlock::setSigner(Bureaucrat const &rSigner)
{
	this->_pSigner = &rSigner;
}

void			OfficeBlock::setExecutor(Bureaucrat const &rExecutor)
{
	this->_pExecutor = &rExecutor;
}

void			OfficeBlock::doBureaucracy(std::string const &rFormName, std::string const &rFormTarget)
					throw (InternNotSetException, SignerNotSetException, ExecutorNotSetException,
						SignerGradeTooLowException, ExecutorGradeTooLowException,
						UnknownFormException)
{
	AForm		*p_form;

	if (this->_pIntern == NULL)
		throw (InternNotSetException());
	if (this->_pSigner == NULL)
		throw (SignerNotSetException());
	if (this->_pExecutor == NULL)
		throw (ExecutorNotSetException());
	if (!(p_form = this->_pIntern->makeForm(rFormName, rFormTarget)))
		throw (UnknownFormException());

	try
	{
		this->_pSigner->signForm(*p_form);
		this->_pExecutor->executeForm(*p_form);
	}
	catch (Bureaucrat::SignerGradeTooLowException)
	{
		throw (SignerGradeTooLowException());
	}
	catch (Bureaucrat::ExecutorGradeTooLowException)
	{
		throw (ExecutorGradeTooLowException());
	}
}

				OfficeBlock::OfficeBlock(void) :
				_pIntern(NULL),
				_pSigner(NULL),
				_pExecutor(NULL)
{
}

				OfficeBlock::OfficeBlock(Intern const &rIntern, Bureaucrat const &rSigner, \
					Bureaucrat const &rExecutor) :
				_pIntern(&rIntern),
				_pSigner(&rSigner),
				_pExecutor(&rExecutor)
{
}

				OfficeBlock::~OfficeBlock(void)
{
}

const char		*OfficeBlock::InternNotSetException::what() const throw ()
{
	return ("OfficeBlock::InternNotSetException");
}

const char		*OfficeBlock::SignerNotSetException::what() const throw ()
{
	return ("OfficeBlock::SignerNotSetException");
}

const char		*OfficeBlock::ExecutorNotSetException::what() const throw ()
{
	return ("OfficeBlock::ExecutorNotSetException");
}

const char		*OfficeBlock::SignerGradeTooLowException::what() const throw ()
{
	return ("OfficeBlock::SignerGradeTooLowException");
}

const char		*OfficeBlock::ExecutorGradeTooLowException::what() const throw ()
{
	return ("OfficeBlock::ExecutorGradeTooLowException");
}

const char		*OfficeBlock::UnknownFormException::what() const throw ()
{
	return ("OfficeBlock::UnknownFormException");
}

				OfficeBlock::OfficeBlock(OfficeBlock const &rSrc)
{
	static_cast<void>(rSrc);
}

OfficeBlock		&OfficeBlock::operator=(OfficeBlock const &rRhs)
{
	static_cast<void>(rRhs);
	return (*this);
}