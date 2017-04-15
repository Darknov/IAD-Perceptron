#include "PlotDrawer.h"

#include "Debug.h"

PlotDrawer::PlotDrawer()
{
	Gnuplot::set_GNUPlotPath("C:\\gnuplot\\bin");
	gnuplot = new Gnuplot();

}

void PlotDrawer::addPlot(Plot plot)
{
	plots.push_back(plot);
	setupPlotsColors();
}

void PlotDrawer::setupPlotsColors()
{
	for (int i = 0; i < plots.size(); i++)
	{
		gnuplot->cmd("set style line " + std::to_string(i + 1) + " linecolor '" + plots[i].color + "'");
	}

}

void PlotDrawer::drawAll()
{
	std::string commandBuffer = "plot ";

	for (int i = 0; i < plots.size(); i++)
	{
			commandBuffer += "'-' with " + plots[i].style + " ls " + std::to_string(i + 1);
			if (i != plots.size() - 1) commandBuffer += ", ";
	}

	gnuplot->cmd(commandBuffer);


	for (Plot plot : plots)
	{

		for (Point plotPoint : plot.points)
		{
			gnuplot->cmd(plotPoint.toString());
		}

		gnuplot->cmd("e");
	}

	
	gnuplot->cmd("pause -1");

}



void PlotDrawer::deleteAll()
{
	gnuplot->cmd("clear");
		plots.clear();
}