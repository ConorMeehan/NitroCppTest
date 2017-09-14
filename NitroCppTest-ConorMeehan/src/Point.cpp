#include "Point.hpp"

namespace NitroTest
{
	Point::Point()
	{
		x = 0;
		y = 0;
	}

	Point::Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int Point::getX() const
	{
		return x;
	}

	int Point::getY() const
	{
		return y;
	}

	bool Point::operator==(const Point & other)
	{
		return x == other.x && y == other.y;
	}

	bool Point::operator!=(const Point & other)
	{
		return !(*this == other);
	}
}