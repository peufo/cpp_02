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
	float diff = total - (areaAB + areaBC + areaCA);

	float smallest = Fixed::getSmallestRepresentable();
	(void)smallest;
	if (diff < 0)
		diff = -diff;
	return (diff <= Fixed::getSmallestRepresentable());
}

static void bspTest(Point const a, Point const b, Point const c, Point const point, bool isInside)
{
	if (isInside)
		std::cout << "Expected inside\t\t";
	else
		std::cout << "Expected outside\t";
	if (bsp(a, b, c, point) == isInside)
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "FAILED\t" << std::endl;
}

int main( void )
{
	Point a(-2.7, 6.12);
	Point b(-3.32, -1.1);
	Point c(5.32, 4.32);

	bspTest(a, b, c, Point(-4.7, 4.32), false);
	bspTest(a, b, c, Point(2.16, 6.24), false);
	bspTest(a, b, c, Point(3.44, 2.96), false);
	bspTest(a, b, c, Point(3, 3), true);
	bspTest(a, b, c, Point(0, 3), true);
	bspTest(a, b, c, Point(-3, 1), true);
	bspTest(a, b, c, Point(-2.94, -0.58), true);

	return 0;
}
