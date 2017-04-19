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
	
	Fptr transferFunction, transferFunctionDerivative;
	double learnSpeed;


public:

	Neuron();
	Neuron(std::vector<double> W, double learnSpeed);
	void setFunctions(Fptr transferFunction, Fptr derivative); // just assign appropriate functions here. By default It'll be sigmoidal function.
	double getOutput();
	void setInput(std::vector<double> X);
	void setInput(double x);
	void setWeights(std::vector<double> W);
	std::vector<double> getWeights();
	void updateWeights(double exp, double res, std::vector<double> X); // tu jest nie ok

};