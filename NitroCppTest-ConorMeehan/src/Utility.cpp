#include "Utility.hpp"
#include <iostream>
#include "Rectangle.hpp"
#include "IntersectionTester.hpp"

namespace NitroTest
{
	void OutputTriangles(std::ostream &output, const std::vector<std::shared_ptr<Rectangle>>& rectangles)
	{
		output << "Input:" << std::endl;
		for (size_t i = 0; i < rectangles.size(); ++i)
		{
			std::shared_ptr<Rectangle> thisRect = rectangles[i];

			output << '\t' << (i + 1) << ": Rectangle at " << thisRect->toString() << std::endl;
		}

		output << std::endl;
	}

	void OutputIntersections(std::ostream &output, const std::vector<std::shared_ptr<Intersection>> intersections)
	{
		output << "Intersections" << std::endl;

		for (size_t i = 0; i < intersections.size(); ++i)
		{
			output << "\tBetween rectangle ";

			auto rectangleIndexes = intersections[i]->getRectangleIndexes();
			for (size_t j = 0; j < rectangleIndexes.size() - 2; ++j)
			{
				output << rectangleIndexes[j] + 1 << ", ";
			}
			output << rectangleIndexes[rectangleIndexes.size() - 2] + 1 << " and ";
			output << rectangleIndexes[rectangleIndexes.size() - 1] + 1 << " at ";
			output << intersections[i]->getIntersection()->toString() << std::endl;
		}
	}

	std::vector<std::vector<int>> generatePowerSet(int a, std::vector<int> set)
	{
		std::vector<std::vector<int>> returnSets;
		returnSets.push_back(std::vector<int>());
		returnSets[0].push_back(a);

		for (const int& element : set)
		{
			size_t s = returnSets.size();
			for (size_t i = 0; i < s; ++i)
			{
				std::vector<int> newSet = returnSets[i];
				newSet.push_back(element);
				returnSets.push_back(newSet);
			}
		}

		returnSets.erase(returnSets.begin());

		return returnSets;
	}
}