#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);
		Point& operator+(const Point& point);
		~Point();
};

#endif
