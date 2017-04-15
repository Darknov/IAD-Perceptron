#include "TheSchool.h"


TheSchool::TheSchool(NeuralNetwork network, std::vector<Point> inputPoints) 
{
	this->network = network;
	for(int i=0; i<network.getNumberOfLayers(); i++)
		for (Neuron n : network.getLayer(i).neurons)
		{
			NeuronTeacher t(n, inputPoints);
			teachers.push_back(t);
		}
}

void TheSchool::washTheirBrains()
{
	for (NeuronTeacher t : teachers)
		t.teach();
}

