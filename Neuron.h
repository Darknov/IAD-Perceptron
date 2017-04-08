#pragma once
#include <vector>
#include "Point.h"

#define variant 3

class Neuron
{
public:
	std::vector<double> W;
	double learnSpeed;
	Neuron();
	Neuron(int numberOfInputs);
	int getResponse(std::vector<double> X);
	void updateWeights(int exp, int res, Point X);


};

