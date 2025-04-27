#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static float subArea(Point const a, Point const b, Point const c)
{
	return (a.getX() * (b.getY() - c.getY())).toFloat();
}

static float area(Point const a, Point const b, Point const c)
{
	float area = (subArea(a, b, c) + subArea(b, c, a) + subArea(c, a, b)) / 2;
	
	if (area < 0)
		return (area * -1);
	return (area);
}

static bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float total(area(a, b, c));
	float areaAB(area(a, b, point));
	float areaBC(area(b, c, point));
	float areaCA(area(c, a, point));

	return (total == (areaAB + areaBC + areaCA));
}

static void bspTest(Point const a, Point const b, Point const c, Point const point, bool expected)
{
	if (expected)
		std::cout << "Expected inside\t\t";
	else
		std::cout << "Expected outside\t";
	if (bsp(a, b, c, point) == expected)
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "FAILED\t" << std::endl;
}

int main( void )
{
	Point a(-3, -2);
	Point b(3.6, 1.07);
	Point c(-2.68, 2.61);

	bspTest(a, b, c, Point(-1.64, 0.63), true);
	bspTest(a, b, c, Point(-3.16, 1.09), false);
	bspTest(a, b, c, Point(0.45, 2.83), false);
	return 0;
}
