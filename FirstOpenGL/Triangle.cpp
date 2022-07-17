#include "Triangle.h"

Triangle::Triangle()
	:
	vertices{ {Point(), Point(), Point()} },
	center{Point()},
	sideLength{0.0f}
{}

Triangle::~Triangle()
{}

Triangle::Triangle(const Point& center, const float& sideLength)
	:
	center{center},
	sideLength{sideLength}
{
	vertices[0] = Point(-sideLength / 2.0f, -sideLength / (2 * sqrtf(3)), 0) + center;	// Left vertex
	vertices[1] = Point(sideLength / 2.0f, -sideLength / (2 * sqrtf(3)), 0) + center;		// Right vertex
	vertices[2] = Point(0, sideLength / sqrt(3), 0) + center;								// Topmost vertex
}

std::array<Point, 3> Triangle::getVertices() const
{
	return vertices;
}