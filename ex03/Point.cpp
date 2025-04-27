#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float x, const float y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point(const Fixed& x, const Fixed& y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& point)
{
	*this = point;
}

Point& Point::operator+(const Point& point)
{
	if (this == &point)
		return (*this);
	this->x = point.x;
	this->y = point.y;
	return (*this);
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
