#ifndef POINT_H
#define POINT_H

namespace NitroTest 
{
	class Point
	{
	private:
		int x;
		int y;
	public:
		Point();
		Point(int x, int y);

		int getX() const;
		int getY() const;

		bool operator==(const Point& other);
		bool operator!=(const Point& other);
	};
}

#endif