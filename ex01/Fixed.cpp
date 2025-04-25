#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}

Fixed::Fixed(const Fixed & fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value)
{
	this->raw = value << this->fractional_bits;
}

Fixed::Fixed(const float value)
{
	this->raw = roundf(value * (1 << this->fractional_bits));
}

float Fixed::toFloat() const
{
	return ((float)this->raw / (1 << this->fractional_bits));
}

int Fixed::toInt() const
{
	return (this->raw >> this->fractional_bits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed & fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->raw = fixed.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return (os << fixed.toFloat());
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}
