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
	this->raw = value * (1 << this->fractional_bits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// OPERATORS

Fixed& Fixed::operator=(const Fixed & fixed)
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

Fixed Fixed::operator+(const Fixed& fixed)
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fixed)
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fixed)
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->raw += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	this->operator++();
	return (old);
}

Fixed& Fixed::operator--()
{
	this->raw -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	this->operator--();
	return (old);
}

bool Fixed::operator==(const Fixed & rhs)
{
	return (this->raw == rhs.raw);
}

bool Fixed::operator<(const Fixed & rhs)
{
	return (this->raw < rhs.raw);
}

bool Fixed::operator>(const Fixed & rhs)
{
	return (this->raw > rhs.raw);
}

bool Fixed::operator<=(const Fixed & rhs)
{
	return (this->raw <= rhs.raw);
}

bool Fixed::operator>=(const Fixed & rhs)
{
	return (this->raw >= rhs.raw);
}

bool Fixed::operator!=(const Fixed & rhs)
{
	return (this->raw != rhs.raw);
}

// METHODS INSTANCE

float Fixed::toFloat() const
{
	return ((float)this->raw / (1 << this->fractional_bits));
}

int Fixed::toInt() const
{
	return (this->raw >> this->fractional_bits);
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

// METHODS STATICS

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}
