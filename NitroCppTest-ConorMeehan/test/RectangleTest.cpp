#include "catch.hpp"
#include "Rectangle.hpp"
#include "json.hpp"

using json = nlohmann::json;
using namespace NitroTest;

TEST_CASE("Rectangle ToString", "[rectangle]")
{
	Rectangle rectangle1(Point(20, 30), 100, 200);

	REQUIRE(rectangle1.toString() == "(20,30), w=100, h=200.");
}

TEST_CASE("Rectangle Width Height constructor", "[rectangle]")
{
	Rectangle rectangle(Point(1, 2), 10, 20);

	REQUIRE(rectangle.getTopLeft() == Point(1, 2));
	REQUIRE(rectangle.getWidth() == 10);
	REQUIRE(rectangle.getHeight() == 20);
}

TEST_CASE("Rectangle Width Height constructor negative w/h", "[rectangle]")
{
	Rectangle* rect;
	REQUIRE_THROWS(rect = new Rectangle(Point(1, 2), -10, 20));
	REQUIRE_THROWS(rect = new Rectangle(Point(1, 2), 10, -20));
	REQUIRE_THROWS(rect = new Rectangle(Point(1, 2), -10, -20));
}

TEST_CASE("Rectangle Bottom Right point constructor", "[rectangle]")
{
	Rectangle rectangle(Point(1, 2), Point(11, 22));

	REQUIRE(rectangle.getTopLeft() == Point(1, 2));
	REQUIRE(rectangle.getWidth() == 10);
	REQUIRE(rectangle.getHeight() == 20);
}

TEST_CASE("Rectangle From Json", "[rectangle]")
{
	json rectangleJson1 = { {"x", 0}, {"y", 5}, {"w", 10}, {"h", 20} };

	Rectangle rectangle1 = rectangleJson1;

	Point position = rectangle1.getTopLeft();

	REQUIRE(rectangle1.toString() == "(0,5), w=10, h=20.");
}

TEST_CASE("Rectangle From Incorrect Json", "[rectangle]")
{
	json rectangleJson1 = {};

	Rectangle rectangle1;
	REQUIRE_THROWS(rectangle1 = rectangleJson1);
}

TEST_CASE("Rectangle GetBottomRight", "[rectangle]")
{
	Rectangle rectangle1(Point(20, 30), 100, 200);

	REQUIRE(rectangle1.getBottomRight() == Point(120, 230));
}