#include "catch.hpp"
#include <vector>
#include "RectangleIntersector.hpp"
#include "Rectangle.hpp"

using namespace NitroTest;

TEST_CASE("RectangleIntersector doRectanglesIntersect false", "[rectangleIntersector]")
{
	auto rectangle1 = std::make_shared<Rectangle>(Point(0, 0), 100, 100);
	auto rectangle2 = std::make_shared<Rectangle>(Point(1000, 20), 100, 50);

	bool rectanglesIntersect = NitroTest::doRectanglesIntersect(*rectangle1, *rectangle2);
	REQUIRE(rectanglesIntersect == false);
}

TEST_CASE("RectangleIntersector doRectanglesIntersect left", "[rectangleIntersector]")
{
	auto rectangle1 = std::make_shared<Rectangle>(Point(0, 0), 100, 100);
	auto rectangle2 = std::make_shared<Rectangle>(Point(-50, 20), 100, 50);

	bool rectanglesIntersect = NitroTest::doRectanglesIntersect(*rectangle1, *rectangle2);
	REQUIRE(rectanglesIntersect == true);
}

TEST_CASE("RectangleIntersector doRectanglesIntersect right", "[rectangleIntersector]")
{
	auto rectangle1 = std::make_shared<Rectangle>(Point(0, 0), 100, 100);
	auto rectangle2 = std::make_shared<Rectangle>(Point(50, 20), 100, 50);

	bool rectanglesIntersect = NitroTest::doRectanglesIntersect(*rectangle1, *rectangle2);
	REQUIRE(rectanglesIntersect == true);
}

TEST_CASE("RectangleIntersector doRectanglesIntersect top", "[rectangleIntersector]")
{
	auto rectangle1 = std::make_shared<Rectangle>(Point(0, 0), 100, 100);
	auto rectangle2 = std::make_shared<Rectangle>(Point(20, -50), 50, 100);

	bool rectanglesIntersect = NitroTest::doRectanglesIntersect(*rectangle1, *rectangle2);
	REQUIRE(rectanglesIntersect == true);
}

TEST_CASE("RectangleIntersector doRectanglesIntersect bottom", "[rectangleIntersector]")
{
	auto rectangle1 = std::make_shared<Rectangle>(Point(0, 0), 100, 100);
	auto rectangle2 = std::make_shared<Rectangle>(Point(20, 50), 50, 100);

	bool rectanglesIntersect = NitroTest::doRectanglesIntersect(*rectangle1, *rectangle2);
	REQUIRE(rectanglesIntersect == true);
}

TEST_CASE("RectangleIntersector Intersect left", "[rectangleIntersector]")
{
	std::vector<std::shared_ptr<Rectangle>> rectangles;
	rectangles.push_back(std::make_shared<Rectangle>(Point(0, 0), 100, 100));
	rectangles.push_back(std::make_shared<Rectangle>(Point(-50, 20), 100, 50));

	std::shared_ptr<Rectangle> intersectionRect = NitroTest::getIntersectionRectangle(rectangles);

	REQUIRE(intersectionRect->toString() == "(0,20), w=50, h=50.");
}

TEST_CASE("RectangleIntersector Intersect right", "[rectangleIntersector]")
{
	std::vector<std::shared_ptr<Rectangle>> rectangles;
	rectangles.push_back(std::make_shared<Rectangle>(Point(0, 0), 100, 100));
	rectangles.push_back(std::make_shared<Rectangle>(Point(50, 20), 100, 50));

	std::shared_ptr<Rectangle> intersectionRect = NitroTest::getIntersectionRectangle(rectangles);

	REQUIRE(intersectionRect->toString() == "(50,20), w=50, h=50.");
}

TEST_CASE("RectangleIntersector Intersect top", "[rectangleIntersector]")
{
	std::vector<std::shared_ptr<Rectangle>> rectangles;
	rectangles.push_back(std::make_shared<Rectangle>(Point(0, 0), 100, 100));
	rectangles.push_back(std::make_shared<Rectangle>(Point(20, -50), 50, 100));

	std::shared_ptr<Rectangle> intersectionRect = NitroTest::getIntersectionRectangle(rectangles);

	REQUIRE(intersectionRect->toString() == "(20,0), w=50, h=50.");
}

TEST_CASE("RectangleIntersector Intersect bottom", "[rectangleIntersector]")
{
	std::vector<std::shared_ptr<Rectangle>> rectangles;
	rectangles.push_back(std::make_shared<Rectangle>(Point(0, 0), 100, 100));
	rectangles.push_back(std::make_shared<Rectangle>(Point(20, 50), 50, 100));

	std::shared_ptr<Rectangle> intersectionRect = NitroTest::getIntersectionRectangle(rectangles);

	REQUIRE(intersectionRect->toString() == "(20,50), w=50, h=50.");
}

TEST_CASE("RectangleIntersector Intersect 2", "[rectangleIntersector]")
{
	std::vector<std::shared_ptr<Rectangle>> rectangles;
	rectangles.push_back(std::make_shared<Rectangle>(Point(120, 200), 250, 150));
	rectangles.push_back(std::make_shared<Rectangle>(Point(160, 140), 350, 190));

	std::shared_ptr<Rectangle> intersectionRect = NitroTest::getIntersectionRectangle(rectangles);

	REQUIRE(intersectionRect->toString() == "(160,200), w=210, h=130.");
}

TEST_CASE("RectangleIntersector Intersect 3", "[rectangleIntersector]")
{
	std::vector<std::shared_ptr<Rectangle>> rectangles;
	rectangles.push_back(std::make_shared<Rectangle>(Point(100, 100), 250, 80));
	rectangles.push_back(std::make_shared<Rectangle>(Point(140, 160), 250, 100));
	rectangles.push_back(std::make_shared<Rectangle>(Point(160, 140), 350, 190));

	std::shared_ptr<Rectangle> intersectionRect = NitroTest::getIntersectionRectangle(rectangles);

	REQUIRE(intersectionRect->toString() == "(160,160), w=190, h=20.");
}

TEST_CASE("RectangleIntersector Intersect 4", "[rectangleIntersector]")
{
	std::vector<std::shared_ptr<Rectangle>> rectangles;
	rectangles.push_back(std::make_shared<Rectangle>(Point(100, 100), 250, 80));
	rectangles.push_back(std::make_shared<Rectangle>(Point(140, 160), 250, 100));
	rectangles.push_back(std::make_shared<Rectangle>(Point(160, 140), 350, 190));
	rectangles.push_back(std::make_shared<Rectangle>(Point(170, 150), 100, 100));

	std::shared_ptr<Rectangle> intersectionRect = NitroTest::getIntersectionRectangle(rectangles);

	REQUIRE(intersectionRect->toString() == "(170,160), w=100, h=20.");
}