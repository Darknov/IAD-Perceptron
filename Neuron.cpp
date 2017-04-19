#include "Neuron.h"

double sigmoid(double z)
{
	return 1.0 / (1.0 + pow(2.72, -1 * z));
}

double sigmoidDerivative(double z)
{
	return pow(2.72, z) / ((2.72 + 1)*(2.72 + 1));
}

Neuron::Neuron()
{
	for (int i = 0; i < 2; i++)
	{
		W[i] = 1;
		learnSpeed = 0.1;
		setFunctions(sigmoid, sigmoidDerivative);
	}
}

Neuron::Neuron(std::vector<double> W, double learnSpeed)
{
	this->W = W;
	this->learnSpeed = learnSpeed;
	setFunctions(sigmoid, sigmoidDerivative);
}

Neuron::Neuron(std::vector<double> W, double learnSpeed, Fptr transferFunction, Fptr transferFunctionDerivative)
{
	this->W = W;
	this->learnSpeed = learnSpeed;
	setFunctions(transferFunction, transferFunctionDerivative);
}

void Neuron::setInput(std::vector<double> X)
{
	this->X = X;
}

void Neuron::setInput(double x)
{
	X.push_back(x);
}

void Neuron::setWeights(std::vector<double> W)
{
	this->W = W;
}

std::vector<double> Neuron::getWeights()
{
	return W;
}

double Neuron::getOutput()
{
	double z = 0;
	
	for (int i = 0; i < W.size(); i++)
	{
		z += X[i] * W[i];
	}

	sumOfInputs = z;
	output = transferFunction(z);
	return output;
}

void Neuron::setFunctions(Fptr transferFunction, Fptr derivative)
{
	this->transferFunction = transferFunction;
	this->transferFunctionDerivative = derivative;
}

void Neuron::updateWeights(double exp, double res, std::vector<double> X)
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

void Neuron::calcutaleOutputGradient(double value)
{
	gradient = (output - value)*Neuron::transferFunctionDerivative(sumOfInputs);
}

void Neuron::calcutaleHiddenGradient(std::vector<double> gradientsInNextLayer, std::vector<double> weightsInNextLayer)
{
	gradient = 0;

	for (int i = 0; i < gradientsInNextLayer.size() - 1; i++)
	{
		gradient = gradient + gradientsInNextLayer[i] * weightsInNextLayer[i];
	}

	gradient = gradient * Neuron::transferFunctionDerivative(sumOfInputs);
}

double Neuron::getGradient()
{
	return gradient;
}