#include <iostream>
#include "Neuron.h"
#include "Debug.h"


Neuron::Neuron(int numberOfInputs)
{
	learnSpeed = 0.01;

	for (int i = 0; i < numberOfInputs; i++)
	{
		W.push_back(1);
	}
}

Neuron::Neuron()
{
	int numberOfInputs = 2;

	learnSpeed = 0.01;

	for (int i = 0; i < numberOfInputs; i++)
	{
		W.push_back(1);
	}
}

int Neuron::getResponse(std::vector<double> X)
{
	int output;

	if (X.size() != W.size())
		std::cerr << "Niepoprawna ilosc zmiennych wejsciowych " << std::endl;

		// funkcja aktywacji jest do zmiany gdzieś tutaj

		if(W[0]*X[0] + W[1]*X[1] > 0.0) output = 1;
		else output = 0;


	return output;
}

void Neuron::updateWeights(int exp, int res, Point X)
{
	switch (variant)
	{
	case 1:
		if (exp == res)
		{
			W[0] += X.x * learnSpeed;
			W[1] += X.y * learnSpeed;
		}
		else
		{
			W[0] -= X.x * learnSpeed;
			W[1] -= X.y * learnSpeed;
		}
		break;
	case 2:
		if (exp == 0 && res == 0)
		{
			W[0] -= X.x * learnSpeed;
			W[1] -= X.y * learnSpeed;
		}
		if (exp == 0 && res == 1)
		{
			W[0] += X.x * learnSpeed;
			W[1] += X.y * learnSpeed;
		}
		if (exp == 1 && res == 1)
		{
			W[0] -= X.x * learnSpeed;
			W[1] -= X.y * learnSpeed;
		}
		if (exp == 1 && res == 0)
		{
			W[0] -= X.x * learnSpeed;
			W[1] -= X.y * learnSpeed;
		}
		break;
	case 3:

		if (exp == 0 && res == 1)
		{
			W[0] -= X.x * learnSpeed;
			W[1] -= X.y * learnSpeed;
		}
		else if (exp == 1 && res == 0)
		{
			W[0] += X.x * learnSpeed;
			W[1] += X.y * learnSpeed;
		}
		break;
	}

	Debug::log(std::to_string(W[0]) + " " + std::to_string(W[1]));
}

