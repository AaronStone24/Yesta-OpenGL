#pragma once
#include "Point.h"
#include <array>

class Triangle
{
public:
	Triangle();
	~Triangle();
	Triangle(const Point& center, const float& sideLength);
	std::array<Point, 3> getVertices() const;
	
private:
	std::array<Point,3> vertices;
	const Point center;
	const float sideLength;
};

