#include "Plot.h"


Plot::Plot(std::string color, std::vector<Point> points, std::string style)
{
	this->color = color;
	this->points = points;
	this->style = style;
}

Plot::Plot(std::vector<Point> points, std::string style)
{
	this->points = points;
	this->style = style;
	color = "black";
}

Plot::Plot(std::string color, std::string style)
{
	this->color = color;
	this->style = style;
}

Plot::Plot(std::string style)
{
	this->style = style;
	color = "black";
}

Plot::Plot()
{
	color = "black";
	style = "points";
}

void Plot::addPoint(Point point)
{
	points.push_back(point);
}

void Plot::deletePoint(int index)
{
	//// spartan version

	//std::vector<Point> newPoints;

	//for (int i = 0; i < points.size(); i++)
	//	if (i != index) newPoints.push_back(points[i]);
	//
	//points = newPoints;
	points.erase(points.begin() + index);
}
