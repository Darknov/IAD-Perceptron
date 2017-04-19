#pragma once

#include <vector>
#include <cmath>

typedef double (*Fptr)(double);

#define variant 3

class Neuron
{
private:

	std::vector<double> X;
	std::vector<double> W;
	std::vector<double> previousDeltaWeights;

	Fptr transferFunction, transferFunctionDerivative;
	double learnSpeed;
	double gradient;
	double output;
	double sumOfInputs;
	double momentum;
	


public:

	Neuron();
	Neuron(std::vector<double> W, double learnSpeed);
	Neuron(std::vector<double> W, double learnSpeed, Fptr transferFunction, Fptr transferFunctionDerivative);
	void setFunctions(Fptr transferFunction, Fptr derivative); // just assign appropriate functions here. By default It'll be sigmoidal function.
	double getOutput(); // if i remember, this function should do everythning what's needed to calculate output and returns it.
	void setInput(std::vector<double> X);
	void setInput(double x);
	void setWeights(std::vector<double> W);
	std::vector<double> getWeights();
	void updateWeights(double exp, double res, std::vector<double> X); // tu jest nie ok
	void updateWeights();
	void calcutaleOutputGradient(double value);
	void calcutaleHiddenGradient(std::vector<double> gradientsInNextLayer, std::vector<double> weightsInNextLayer);
	double getGradient();

};