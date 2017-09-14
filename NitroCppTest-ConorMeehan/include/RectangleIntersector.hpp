#ifndef RECTANGLEINTERSECTOR_H
#define RECTANGLEINTERSECTOR_H
#include <vector>
#include <memory>

namespace NitroTest
{
	class Rectangle;

	bool doRectanglesIntersect(const Rectangle& rectangle1, const Rectangle& rectangle2);
	std::shared_ptr<Rectangle> getIntersectionRectangle(const std::vector<std::shared_ptr<Rectangle>> rectangles);
}
#endif