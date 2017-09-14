#include "Rectangle.hpp"

namespace NitroTest
{
	Rectangle::Rectangle() 
		: topLeft(Point(0, 0)), width(0), height(0)
	{
	}

	Rectangle::Rectangle(Point topLeft, int width, int height) 
		: topLeft(topLeft), width(width), height(height)
	{
		if (width <= 0 || height <= 0)
		{
			throw std::invalid_argument("Width and height must be positive integers.");
		}
		bottomRight = Point(topLeft.getX() + width, topLeft.getY() + height);
	}

	Rectangle::Rectangle(Point topLeft, Point bottomRight)
		: topLeft(topLeft), bottomRight(bottomRight)
	{
		width = bottomRight.getX() - topLeft.getX();
		height = bottomRight.getY() - topLeft.getY();
	}

	Point Rectangle::getTopLeft() const
	{
		return topLeft;
	}

	Point Rectangle::getBottomRight() const
	{
		return bottomRight;
	}

	int Rectangle::getWidth() const
	{
		return width;
	}

	int Rectangle::getHeight() const
	{
		return height;
	}

	std::string Rectangle::toString() const
	{
		std::stringstream ss;
		ss << "(" << topLeft.getX() << "," << topLeft.getY() << "), w=" << width << ", h=" << height << ".";
		return ss.str();
	}

	void from_json(const nlohmann::json& j, Rectangle& r) 
	{
		int x = j.at("x").get<int>();
		int y = j.at("y").get<int>();
		int w = j.at("w").get<int>();
		int h = j.at("h").get<int>();
		r = Rectangle(Point(x, y), w, h);
	}
}