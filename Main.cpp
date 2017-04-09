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

	std::cout << "Podaj liczbe warstw: " << std::endl;
	std::cin >> numberOfLayers;

	howMuchNeuronsInEachLayer = new int[numberOfLayers];

	for (int i = 0; i < numberOfLayers; i++)
	{
		std::cout << "Ile ma byc neuronow w warstwie " + std::to_string(i) + ": " << std::endl;
		std::cin >> howMuchNeuronsInEachLayer[i];
	}

	NetworkCreationMode mode;
	int choice;
	std::cout << "Wczytac siec z pliku, czy utworzyc nowa? [0/1]" << std::endl;
	std::cin >> choice;

	if (choice == 0) mode = LoadFromFile; else mode = CreateNew;

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

