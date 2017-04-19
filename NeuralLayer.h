#pragma once
#include <vector>
#include "Neuron.h"

class NeuralLayer
{
private:
	std::vector<Neuron> neurons;
	Neuron bias; // to jest pomocnicze pole. Ale ważne.

public:
	bool useBias;
	NeuralLayer(); 
	NeuralLayer(std::vector<Neuron> neurons, Neuron bias); // dla wczytywania z fajla. Bias musimy tu podawać, bo tak jest dobrze.
	void addNeuron(Neuron& n);
	void addBias(Neuron& bias);
	void setBiasPermissions(bool can);
	void setBias(Neuron bias);
	int getSize();
	Neuron& getNeuron(int index);
	Neuron& getBias();
	void setFunctions(Fptr transferFunction, Fptr derivative);
	std::vector<double> getGradients();
	std::vector<double> getWeightsOnInput(int index);

};

