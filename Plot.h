#pragma once

#include <string>
#include <vector>

#include "Point.h"

class Plot
{
public:
	std::string color;
	std::string style;
	std::vector<Point> points;

	Plot(std::string color, std::vector<Point> points, std::string style);
	Plot(std::vector<Point> points, std::string style);
	Plot(std::string color, std::string style);
	Plot(std::string style);
	Plot();

	void addPoint(Point point);
	void deletePoint(int index);
};

