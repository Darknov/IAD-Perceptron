#include "NeuronTeacher.h"
#include "Debug.h"
#include "Random.h"


NeuronTeacher::NeuronTeacher(Neuron neuron, std::vector<Point> inputPoints)
{
	this->neuron = neuron;
	this->inputPoints = inputPoints;
	upPoints = Plot("red", "points");
	downPoints = Plot("blue", "points");

	for (Point p : inputPoints)
	{
		downPoints.addPoint(p);
	}

}

void NeuronTeacher::teach()
{

	int response, expectedResponse;
	int i, j, k, l;
	Random random;
	for (k = 0; k < 1000; k++)
	{
		i = random.nextIntExcludingTop(0, inputPoints.size());
		expectedResponse = getExpectedResponse(inputPoints[i]);
		neuron.setInput(inputPoints[i].toVector());
		response = neuron.getOutput();
		neuron.updateWeights(expectedResponse, response, inputPoints[i].toVector());

		if (!(k % 10))
		{
			downPoints.points.clear();
			upPoints.points.clear();
			drawer.deleteAll();
			for (j = 0; j < inputPoints.size(); j++)
			{
				neuron.setInput(inputPoints[i].toVector());
				if (neuron.getOutput() == 1) { downPoints.addPoint(inputPoints[j]); }
				else { upPoints.addPoint(inputPoints[j]); }
			}
			refreshPlots();
		}

	}

}

int NeuronTeacher::getExpectedResponse(Point a)
{
	if (a.x>a.y) return 1;
	else return 0;

}

void NeuronTeacher::refreshPlots()
{
	drawer.addPlot(downPoints);
	drawer.addPlot(upPoints);
	drawer.drawAll();

}