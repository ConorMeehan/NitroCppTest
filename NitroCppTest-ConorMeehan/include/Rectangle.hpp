#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "json.hpp"
#include "Point.hpp"

namespace NitroTest
{
	class Rectangle
	{
	private:
		Point topLeft;
		Point bottomRight;
		int width;
		int height;
 
	public:
		Rectangle();
		Rectangle(Point position, int width, int height);
		Rectangle(Point topLeft, Point bottomRight);

		Point getTopLeft() const;
		Point getBottomRight() const;

		int getWidth() const;
		int getHeight() const;

		std::string toString() const;
	};

	void from_json(const nlohmann::json& j, Rectangle& p);
}
#endif