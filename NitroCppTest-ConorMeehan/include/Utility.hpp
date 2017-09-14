#ifndef UTILITY_H
#define UTILITY_H
#include <vector>
#include <memory>

namespace NitroTest
{
	class Rectangle;
	class Intersection;

	std::vector<std::vector<int>> generatePowerSet(int a, std::vector<int> set);

	void OutputTriangles(std::ostream &output, const std::vector<std::shared_ptr<Rectangle>>& rectangles);
	void OutputIntersections(std::ostream &output, const std::vector<std::shared_ptr<Intersection>> intersections);
}

#endif