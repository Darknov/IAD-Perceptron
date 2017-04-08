#include "Point.h"

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

std::string Point::toString()
{
	return std::to_string(x) + " " + std::to_string(y);
}

std::vector<double> Point::toVector()
{
	std::vector<double> pointAsVector;

	pointAsVector.push_back(x);
	pointAsVector.push_back(y);

	return pointAsVector;
}
