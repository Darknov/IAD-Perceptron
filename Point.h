#pragma once
#include <string>
#include <vector>
class Point
{
public:
	double x, y;
	Point(double x, double y);
	Point();
	std::string toString();
	std::vector<double> toVector();
};

