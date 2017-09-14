#include "catch.hpp"
#include "Point.hpp"

using namespace NitroTest;

TEST_CASE("Point ==", "[Point]")
{
	Point p1(0, 0);
	Point p2(10, 10);
	Point p3(10, 10);

	REQUIRE((p1 == p2) == false);
	REQUIRE((p2 == p3) == true);
}

TEST_CASE("Point !=", "[Point]")
{
	Point p1(0, 0);
	Point p2(10, 10);
	Point p3(10, 10);

	REQUIRE((p1 != p2) == true);
	REQUIRE((p2 != p3) == false);
}