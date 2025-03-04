/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:08:55 by mel-bouh          #+#    #+#             */
/*   Updated: 2025/03/04 19:09:27 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : _value(number << bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) {
	_value = roundf(number * (1 << bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_value = fixed._value;
	return *this;
}

Fixed	Fixed::operator+(const Fixed &fix) const {
	Fixed	result;
	result.setRawBits(this->_value + fix.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &fix) const {
	Fixed	result;
	result.setRawBits(this->_value - fix.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &fix) const {
	Fixed	result;
	result.setRawBits((this->_value * fix.getRawBits()) >> bits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &fix) const {
	Fixed	result;
	result.setRawBits((this->_value << bits) / fix.getRawBits());
	return (result);
}

bool	Fixed::operator>(const Fixed &fix) const {
	if (this->_value > fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &fix) const {
	if (this->_value < fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &fix) const {
	if (this->_value >= fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &fix) const {
	if (this->_value <= fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &fix) const {
	if (this->_value == fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &fix) const {
	if (this->_value != fix.getRawBits())
		return (true);
	return (false);
}

Fixed&	Fixed::operator++(void) {
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	_value++;
	return (tmp);
}

Fixed&	Fixed::operator--(void) {
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	_value--;
	return (tmp);
}

float	Fixed::toFloat(void) const {
	return ((float)_value / (1 << bits));
}

int	Fixed::toInt(void) const {
	return (_value >> bits);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

Fixed&	Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

std::ostream&	operator<<(std::ostream &os, const Fixed& fix) {
	os << fix.toFloat();
	return (os);
}
