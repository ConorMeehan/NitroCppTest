#include "catch.hpp"
#include "IntersectionTester.hpp"
#include "json.hpp"
#include "Rectangle.hpp"

using json = nlohmann::json;
using namespace NitroTest;

TEST_CASE("IntersectionTester Parse From Json Empty", "[IntersectionTester]")
{
	json rectangleJsonArray = {};

	IntersectionTester IntersectionTester(rectangleJsonArray);

	REQUIRE(IntersectionTester.getCount() == 0);
}

TEST_CASE("IntersectionTester Parse From Json", "[IntersectionTester]")
{
	json rectangleJsonArray = { { { "x", 1 },{ "y", 2 },{ "w", 10 },{ "h", 20 } },
								{ { "x", 3 },{ "y", 4 },{ "w", 20 },{ "h", 30 } } };

	IntersectionTester IntersectionTester(rectangleJsonArray);

	REQUIRE(IntersectionTester.getCount() == 2);

	std::shared_ptr<Rectangle> rect0 = IntersectionTester.getRectangle(0);
	Point position0 = rect0->getTopLeft();
	REQUIRE(position0.getX() == 1);
	REQUIRE(position0.getY() == 2);
	REQUIRE(rect0->getWidth() == 10);
	REQUIRE(rect0->getHeight() == 20);

	std::shared_ptr<Rectangle> rect1 = IntersectionTester.getRectangle(1);
	Point position1 = rect1->getTopLeft();
	REQUIRE(position1.getX() == 3);
	REQUIRE(position1.getY() == 4);
	REQUIRE(rect1->getWidth() == 20);
	REQUIRE(rect1->getHeight() == 30);
}

TEST_CASE("IntersectionTester Parse From Json Over Max Count", "[IntersectionTester]")
{
	std::string oneRectangleString = "{ \"x\": 100, \"y\" : 100, \"w\" : 250, \"h\" : 80 }";
	std::string overMaxRectStrings = "{\"rects\": [ ";

	for (int i = 0; i < IntersectionTester::MAX_RECTANGLE_COUNT * 2; ++i)
	{
		overMaxRectStrings.append(oneRectangleString + ',');
	}
	overMaxRectStrings.append(oneRectangleString + " ] }");

	json rectangleJsonArray = json::parse(overMaxRectStrings);

	IntersectionTester intersectionTester(rectangleJsonArray["rects"]);

	REQUIRE(intersectionTester.getCount() == IntersectionTester::MAX_RECTANGLE_COUNT);
}

TEST_CASE("IntersectionTester Rectangles don't intersect", "[IntersectionTester]")
{
	json rectangleJsonArray = { { { "x", 1000 },{ "y", 2 },{ "w", 10 },{ "h", 20 } },
								{ { "x", 5000 },{ "y", 2 },{ "w", 10 },{ "h", 20 } },
								{ { "x", 5 },{ "y", 5 },{ "w", 20 },{ "h", 30 } } };

	IntersectionTester intersectionTester(rectangleJsonArray);
	auto intersections = intersectionTester.getIntersections();

	REQUIRE(intersections.size() == 0);
}

TEST_CASE("IntersectionTester Two rectangles intersect", "[IntersectionTester]")
{
	json rectangleJsonArray = { { { "x", 1 },{ "y", 2 },{ "w", 10 },{ "h", 20 } },
								{ { "x", 5 },{ "y", 5 },{ "w", 20 },{ "h", 30 } } };

	IntersectionTester intersectionTester(rectangleJsonArray);
	auto intersections = intersectionTester.getIntersections();
	
	REQUIRE(intersections.size() == 1);
	REQUIRE(intersections[0]->getRectangleIndexes()[0] == 0);
	REQUIRE(intersections[0]->getRectangleIndexes()[1] == 1);
	REQUIRE(intersections[0]->getIntersection()->toString() == "(5,5), w=6, h=17.");
}

#pragma region
void checkMatch7(int &matchCount, std::vector<int> indexes, std::shared_ptr<Rectangle> rect)
{
	if (indexes[0] == 1 && indexes[1] == 2 && indexes[2] == 3)
	{
		if (rect->toString() == "(160,200), w=210, h=60.")
		{
			++matchCount;
		}
	}
}

void checkMatch6(int &matchCount, std::vector<int> indexes, std::shared_ptr<Rectangle> rect)
{
	if (indexes[0] == 0 && indexes[1] == 2 && indexes[2] == 3)
	{
		if (rect->toString() == "(160,160), w=190, h=20.")
		{
			++matchCount;
		}
	}
}

void checkMatch5(int &matchCount, std::vector<int> indexes, std::shared_ptr<Rectangle> rect)
{
	if (indexes[0] == 2 && indexes[1] == 3)
	{
		if (rect->toString() == "(160,160), w=230, h=100.")
		{
			++matchCount;
		}
	}
}

void checkMatch4(int &matchCount, std::vector<int> indexes, std::shared_ptr<Rectangle> rect)
{
	if (indexes[0] == 1 && indexes[1] == 3)
	{
		if (rect->toString() == "(160,200), w=210, h=130.")
		{
			++matchCount;
		}
	}
}

void checkMatch3(int &matchCount, std::vector<int> indexes, std::shared_ptr<Rectangle> rect)
{
	if (indexes[0] == 1 && indexes[1] == 2)
	{
		if (rect->toString() == "(140,200), w=230, h=60.")
		{
			++matchCount;
		}
	}
}

void checkMatch2(int &matchCount, std::vector<int> indexes, std::shared_ptr<Rectangle> rect)
{
	if (indexes[0] == 0 && indexes[1] == 3)
	{
		if (rect->toString() == "(160,140), w=190, h=40.")
		{
			++matchCount;
		}
	}
}

void checkMatch1(int &matchCount, std::vector<int> indexes, std::shared_ptr<Rectangle> rect)
{
	if (indexes[0] == 0 && indexes[1] == 2)
	{
		if (rect->toString() == "(140,160), w=210, h=20.")
		{
			++matchCount;
		}
	}
}
#pragma endregion Nicer if these comparisons can be collapsiable

TEST_CASE("IntersectionTester Given example", "[IntersectionTester]")
{
	const char * rectsJsonString = "{\"rects\": [ {\"x\": 100, \"y\" : 100, \"w\" : 250, \"h\" : 80 }, "
												 "{\"x\": 120, \"y\" : 200, \"w\" : 250, \"h\" : 150 }, "
												 "{\"x\": 140, \"y\" : 160, \"w\" : 250, \"h\" : 100 }, "
												 "{\"x\": 160, \"y\" : 140, \"w\" : 350, \"h\" : 190 } "
											   "] }";

	json rectangleJsonArray = json::parse(rectsJsonString);

	IntersectionTester IntersectionTester(rectangleJsonArray["rects"]);
	auto intersections = IntersectionTester.getIntersections();

	REQUIRE(intersections.size() == 7);

	int matchCount = 0;

	// Check each intersection agaisnt all the desired results
	// Can't require each one as that would fail the test
	// This is very complicated for a test but it is meant as a functional and not unit test
	for (auto i : intersections)
	{
		auto indexes = i->getRectangleIndexes();
		auto intersectionRect = i->getIntersection();
		if (indexes.size() == 3)
		{
			checkMatch7(matchCount, indexes, intersectionRect);
			checkMatch6(matchCount, indexes, intersectionRect);
		}
		else if(indexes.size() == 2)
		{
			checkMatch5(matchCount, indexes, intersectionRect);
			checkMatch4(matchCount, indexes, intersectionRect);
			checkMatch3(matchCount, indexes, intersectionRect);
			checkMatch2(matchCount, indexes, intersectionRect);
			checkMatch1(matchCount, indexes, intersectionRect);
		}
	}

	REQUIRE(matchCount == 7);
}