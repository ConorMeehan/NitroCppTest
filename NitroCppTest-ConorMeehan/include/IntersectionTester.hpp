#ifndef INTERSECTIONTESTER_H
#define INTERSECTIONTESTER_H
#include <vector>
#include <memory>
#include "json.hpp"

namespace NitroTest
{
	class Rectangle;

	class Intersection
	{
	private:
		std::vector<int> rectangleIndexes;
		std::shared_ptr<Rectangle> intersection;
	public:
		Intersection() {};
		Intersection(std::vector<int> rectangleIndexes, std::shared_ptr<Rectangle> intersection)
			: rectangleIndexes(rectangleIndexes), intersection(intersection) {}
		std::vector<int> getRectangleIndexes() const { return rectangleIndexes; }
		std::shared_ptr<Rectangle> getIntersection() const { return intersection; }
	};

	class IntersectionTester
	{
	private:
		std::vector<std::shared_ptr<Rectangle>> rectangles;

		void parseFromJson(const nlohmann::json& rectanglesJsonArray);

		void checkAllIntersections(std::vector<std::vector<int>> &intersectionIndexes) const;
		void generateIntersections(const size_t &rectangleIndex, std::vector<std::vector<int>> &intersectionIndexes,
													   std::vector<std::shared_ptr<Intersection>> &intersections) const;
	public:
		IntersectionTester(const nlohmann::json& rectanglesJsonArray);
		static const int MAX_RECTANGLE_COUNT;

		int getCount() const;
		std::shared_ptr<Rectangle> getRectangle(int index) const;
		
		const std::vector<std::shared_ptr<Rectangle>>& getRectangles() const;
		std::vector<std::shared_ptr<Intersection>> getIntersections() const;
	};
}
#endif