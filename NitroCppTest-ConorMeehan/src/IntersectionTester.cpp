#include "..\include\IntersectionTester.hpp"
#include "IntersectionTester.hpp"
#include "Rectangle.hpp"
#include "RectangleIntersector.hpp"
#include "json.hpp"
#include <iostream>
#include "Utility.hpp"

namespace NitroTest
{
	const int IntersectionTester::MAX_RECTANGLE_COUNT = 10;

	IntersectionTester::IntersectionTester(const nlohmann::json& rectanglesJsonArray)
	{
		parseFromJson(rectanglesJsonArray);
	}

	void IntersectionTester::parseFromJson(const nlohmann::json& rectanglesJsonArray)
	{
		int count = std::min((int)rectanglesJsonArray.size(), MAX_RECTANGLE_COUNT);

		rectangles.reserve(count);

		for (int i = 0; i < count; ++i)
		{
			auto rectangle = std::shared_ptr<Rectangle>(new Rectangle(rectanglesJsonArray[i]));
			rectangles.push_back(rectangle);
		}
	}

	int IntersectionTester::getCount() const
	{
		return rectangles.size();
	}

	std::shared_ptr<Rectangle> IntersectionTester::getRectangle(int index) const
	{
		return rectangles.at(index);
	}

	const std::vector<std::shared_ptr<Rectangle>>& IntersectionTester::getRectangles() const
	{
		return rectangles;
	}

	void IntersectionTester::checkAllIntersections(std::vector<std::vector<int>> &intersectionIndexes) const
	{
		for (size_t i = 0; i < rectangles.size(); ++i)
		{
			for (size_t j = i + 1; j < rectangles.size(); ++j)
			{
				if (doRectanglesIntersect(*rectangles[i], *rectangles[j]))
				{
					intersectionIndexes[i].push_back(j);
				}
			}
		}
	}

	void IntersectionTester::generateIntersections(const size_t &rectangleIndex, std::vector<std::vector<int>> &intersectionIndexes,
												   std::vector<std::shared_ptr<Intersection>> &intersections) const
	{
		const std::vector<int>& intersectingIndexes = intersectionIndexes[rectangleIndex];

		std::vector<std::vector<int>> sets = generatePowerSet(rectangleIndex, intersectingIndexes);

		for (size_t setIndex = 0; setIndex < sets.size(); ++setIndex)
		{
			std::vector<int> set = sets[setIndex];
			std::vector<std::shared_ptr<Rectangle>> rects;
			for (size_t i = 0; i < set.size(); ++i)
			{
				rects.push_back(rectangles[set[i]]);
			}
			auto intersectionRectangle = getIntersectionRectangle(rects);
			auto intersection = std::make_shared<Intersection>(set, intersectionRectangle);
			intersections.push_back(intersection);
		}
	}

	std::vector<std::shared_ptr<Intersection>> IntersectionTester::getIntersections() const
	{
		std::vector<std::vector<int>> intersectionIndexes;
		intersectionIndexes.resize(rectangles.size());

		checkAllIntersections(intersectionIndexes);

		std::vector<std::shared_ptr<Intersection>> intersections;
		for (size_t rectangleIndex = 0; rectangleIndex < intersectionIndexes.size(); ++rectangleIndex)
		{
			generateIntersections(rectangleIndex, intersectionIndexes, intersections);
		}

		return intersections;
	}
}