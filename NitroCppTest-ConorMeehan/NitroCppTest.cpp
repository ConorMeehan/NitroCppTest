#include<iostream>
#include "json.hpp"
#include <fstream>
#include "IntersectionTester.hpp"
#include "Utility.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Missing rectangle json file name" << std::endl << "Usage : <FileName>" << std::endl;
		return -1;
	}

	std::string fileName = argv[1];

	std::ifstream ifs(fileName, std::ifstream::in);
	nlohmann::json jsonRoot;

	if (ifs.is_open())
	{
		try 
		{
			ifs >> jsonRoot;
		}
		catch(std::exception e)
		{
			std::cout << "Badly formed json input" << std::endl;
			return -1;
		}
		ifs.close();

		try
		{
			NitroTest::IntersectionTester IntersectionTester(jsonRoot["rects"]);

			OutputTriangles(std::cout, IntersectionTester.getRectangles());
			OutputIntersections(std::cout, IntersectionTester.getIntersections());
		}
		catch (nlohmann::detail::exception)
		{
			std::cout << "Problem parsing json input." << std::endl;
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Could not open json file : " << fileName << std::endl;
	}

	std::cout << std::endl;
	return 0;
}