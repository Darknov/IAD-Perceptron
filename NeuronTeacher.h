#pragma once
#include "Neuron.h"
#include "Point.h"
#include "Plot.h"
#include "PlotDrawer.h"

#define UP true
#define DOWN false

class NeuronTeacher
{
public:
	Neuron neuron;
	std::vector<Point> inputPoints;
	
	Plot upPoints;
	Plot downPoints;

	PlotDrawer drawer;

	NeuronTeacher(Neuron neuron, std::vector<Point> inputPoints);
	void teach();

private:
	int getExpectedResponse(Point x);
	void refreshPlots();
};

