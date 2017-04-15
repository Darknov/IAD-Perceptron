#pragma once
#include <iostream>
#include <memory>

#include "PlotDrawer.h"
#include "Random.h"
#include "NeuronTeacher.h"	
#include "Debug.h"
#include "NeuralNetwork.h"
#include "TheSchool.h"
#include "LayerOfNeurons.h"

double linearFunction(double x);

int main(int argc)
{
	NeuralNetwork* perceptron = new NeuralNetwork();
	LayerOfNeurons* kageBunshinNoLayer; // warstwa powielajaca

	kageBunshinNoLayer = new LayerOfNeurons();

	Neuron sampleDuplicationNeuron;
	sampleDuplicationNeuron.setActivationFunction(linearFunction);

	for(int i=0; i<4; i++)
		kageBunshinNoLayer->addNeuron(sampleDuplicationNeuron);

	perceptron->addLayer(*kageBunshinNoLayer);

	std::cin.ignore();
	std::cin.get();
	
	delete perceptron;
	delete kageBunshinNoLayer;
}

double linearFunction(double x)
{
	return x;
}