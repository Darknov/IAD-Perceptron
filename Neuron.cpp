#include "Neuron.h"

double sigmoid(double z)
{
	return 1.0 / (1.0 + pow(2.72, -1 * z));
}

Neuron::Neuron()
{
	for (int i = 0; i < 2; i++)
	{
		W[i] = 1;
		learnSpeed = 0.1;
		setActivationFunction(sigmoid);
	}
}

Neuron::Neuron(std::vector<double> W, double learnSpeed)
{
	this->W = W;
	this->learnSpeed = learnSpeed;
	setActivationFunction(sigmoid);
}

void Neuron::setActivationFunction(ActivationFunction function) // just assign appropriate function here. By default It'll be sigmoidal function.
{
	this->activationFunction = activationFunction;
}

double Neuron::getOutput()
{
	double sum = 0;

	for (int i = 0; i < W.size(); i++)
	{
		sum += X[i] * W[i];
	}

	return activationFunction(sum);
}

void Neuron::setInput(std::vector<double> X)
{
	this->X = X;
}



void Neuron::updateWeights(int exp, int res, std::vector<double> X)
{
	switch (variant)
	{
	case 1:
		if (exp == res)
		{
			for (int i = 0; i < W.size(); i++)
				W[i] += X[i] * learnSpeed;
		}
		else
		{
			for (int i = 0; i < W.size(); i++)
				W[i] -= X[i] * learnSpeed;
		}
		break;
	case 2:
		if (exp == 0 && res == 0)
		{
			for (int i = 0; i < W.size(); i++)
				W[i] -= X[i] * learnSpeed;
		}
		if (exp == 0 && res == 1)
		{
			for (int i = 0; i < W.size(); i++)
				W[i] += X[i] * learnSpeed;
		}
		if (exp == 1 && res == 1)
		{
			for (int i = 0; i < W.size(); i++)
				W[i] -= X[i] * learnSpeed;
		}
		if (exp == 1 && res == 0)
		{
			for (int i = 0; i < W.size(); i++)
				W[i] -= X[i] * learnSpeed;
		}
		break;
	case 3:

		if (exp == 0 && res == 1)
		{
			for (int i = 0; i < W.size(); i++)
				W[i] -= X[i] * learnSpeed;
		}
		else if (exp == 1 && res == 0)
		{
			for (int i = 0; i < W.size(); i++)
				W[i] += X[i] * learnSpeed;
		}
		break;
	}

}