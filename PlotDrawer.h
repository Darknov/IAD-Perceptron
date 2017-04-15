#pragma once

#include <vector>
#include "gnuplot_i.hpp"
#include "Plot.h"

class PlotDrawer
{
public:

	std::vector<Plot> plots;

	Gnuplot* gnuplot;

	PlotDrawer();

	void drawAll();
	void deleteAll();
	void addPlot(Plot plot);
	void setupPlotsColors();


};

