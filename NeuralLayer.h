#pragma once
#include <vector>
#include "Neuron.h"



class NeuralLayer
{
private:
	std::vector<Neuron> neurons;
	Neuron bias;
	bool useBias;

public:
	NeuralLayer(); 
	NeuralLayer(std::vector<Neuron> neurons); // dla wczytywania z fajla
	void addNeuron(Neuron& n);
	void setBias(Neuron& bias);
	void setBiasPermissions(bool can);
	Neuron& getNeuron(int index);
	Neuron& getBias();
	void setFunctions(Fptr transferFunction, Fptr derivative);

};

