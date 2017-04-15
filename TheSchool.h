#pragma once

#include<vector>;
#include "NeuronTeacher.h"
#include "NeuralNetwork.h"

class TheSchool
{
public:
	std::vector<NeuronTeacher> teachers;
	NeuralNetwork network;

	TheSchool(NeuralNetwork network, std::vector<Point> inputPoints);

	void washTheirBrains();
};

