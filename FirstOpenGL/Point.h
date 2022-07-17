#pragma once
#include <utility>

struct Point
{
	float x;
	float y;
	float z;
	
	Point()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	Point(const float x, const float y, const float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Point(const Point& p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
	}
	Point& operator=(const Point& p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
		return *this;
	}
	Point operator+(const Point& p)
	{
		Point result(x + p.x, y + p.y, z + p.z);
		return std::move(result);
	}
	Point operator-(const Point& p)
	{
		Point result(x - p.x, y - p.y, z - p.z);
		return std::move(result);
	}
	Point operator*(const float f)
	{
		Point result(x * f, y * f, z * f);
		return std::move(result);
	}
	Point operator/(const float f)
	{
		Point result(x / f, y / f, z / f);
		return std::move(result);
	}
	
};