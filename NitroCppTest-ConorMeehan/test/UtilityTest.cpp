#include "catch.hpp"
#include "Utility.hpp"
#include "Rectangle.hpp"
#include "Point.hpp"
#include "IntersectionTester.hpp"
#include <vector>
#include <memory>

using namespace NitroTest;

TEST_CASE("Utility Output triangles", "[utility]")
{
	std::vector<std::shared_ptr<Rectangle>> rectangles;

	rectangles.push_back(std::make_shared<Rectangle>(Point(0, 1), 10, 20));
	rectangles.push_back(std::make_shared<Rectangle>(Point(2, 3), 15, 40));

	std::stringstream ss;
	OutputTriangles(ss, rectangles);

	std::stringstream expected;
	expected << "Input:" << std::endl << "\t1: Rectangle at (0,1), w=10, h=20." 
						 << std::endl << "\t2: Rectangle at (2,3), w=15, h=40."
					     << std::endl << std::endl;

	REQUIRE(ss.str() == expected.str());
}

TEST_CASE("Utility Output intersections", "[utility]")
{
	std::vector<std::shared_ptr<Intersection>> intersections;

	std::vector<int> indexes = { 1, 2 };
	intersections.push_back(std::make_shared<Intersection>(indexes, std::make_shared<Rectangle>()));

	indexes.push_back(3);
	intersections.push_back(std::make_shared<Intersection>(indexes, std::make_shared<Rectangle>()));

	std::stringstream ss;
	OutputIntersections(ss, intersections);

	std::stringstream expected;
	expected << "Intersections" << std::endl << "\tBetween rectangle 2 and 3 at (0,0), w=0, h=0."
		<< std::endl << "\tBetween rectangle 2, 3 and 4 at (0,0), w=0, h=0."
		<< std::endl;

	REQUIRE(ss.str() == expected.str());
}

TEST_CASE("Utility Get power sets", "[utility]")
{
	// This test could be alot better.
	// It currently only checks the power sets are the correct size.
	// Checking each set would be unweildy and I can't think of a simple solution

	std::vector<int> s = { 1, 2, 3 };
	auto generatedPowerSet1 = generatePowerSet(0, s);
	REQUIRE(generatedPowerSet1.size() == 7);

	std::vector<int> s2 = { 1, 2, 3, 4 };
	auto generatedPowerSet2 = generatePowerSet(0, s2);
	REQUIRE(generatedPowerSet2.size() == 15);

	std::vector<int> s3 = { 1, 2, 3, 4, 5 };
	auto generatedPowerSet3 = generatePowerSet(0, s3);
	REQUIRE(generatedPowerSet3.size() == 31);
}