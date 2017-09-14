#include "RectangleIntersector.hpp"
#include "Rectangle.hpp"
#include "limits.h"

namespace NitroTest
{
	bool doRectanglesIntersect(const Rectangle& rectangle1, const Rectangle& rectangle2)
	{
		Point tl1 = rectangle1.getTopLeft();
		Point br1 = rectangle1.getBottomRight();
		Point tl2 = rectangle2.getTopLeft();
		Point br2 = rectangle2.getBottomRight();

		return tl1.getX() < br2.getX() && br1.getX() > tl2.getX()
			&& tl1.getY() < br2.getY() && br1.getY() > tl2.getY();
	}

	std::shared_ptr<Rectangle> getIntersectionRectangle(const std::vector<std::shared_ptr<Rectangle>> rectangles)
	{
		int leftX = INT_MIN;
		int rightX = INT_MAX;
		int topY = INT_MIN;
		int bottomY = INT_MAX;

		for (auto &rect : rectangles)
		{
			Point tl = rect->getTopLeft();
			Point br = rect->getBottomRight();

			leftX = std::max(leftX, tl.getX());
			rightX = std::min(rightX, br.getX());
			topY = std::max(topY, tl.getY());
			bottomY = std::min(bottomY, br.getY());
		}

		return std::make_shared<Rectangle>(Point(leftX, topY), Point(rightX, bottomY));
	}
}