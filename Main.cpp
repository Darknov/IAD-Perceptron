#pragma once
#include <iostream>
#include <memory>

#include "PlotDrawer.h"
#include "Random.h"
#include "NeuronTeacher.h"
#include "Debug.h"
#include "NeuralNetwork.h"

int main(int argc)
{
	NeuralNetwork* perceptron;
	int numberOfLayers;
	int* howMuchNeuronsInEachLayer;

	std::cin >> numberOfLayers;

	howMuchNeuronsInEachLayer = new int[numberOfLayers];

	NetworkCreationMode mode = CreateNew;

	switch (mode)
	{
	case LoadFromFile:
		perceptron = new NeuralNetwork(numberOfLayers, howMuchNeuronsInEachLayer);
		break;
	case CreateNew:
	default:
		perceptron = new NeuralNetwork();

	}
	
	delete [] howMuchNeuronsInEachLayer;
	delete perceptron;


	std::cin.get();
}

