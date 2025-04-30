#include "bsp.hpp"

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

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float total(area(a, b, c));
	float areaAB(area(a, b, point));
	float areaBC(area(b, c, point));
	float areaCA(area(c, a, point));
	float diff = total - (areaAB + areaBC + areaCA);

	if (diff < 0)
		diff = -diff;
	return (diff <= Fixed::getSmallestRepresentable());
}