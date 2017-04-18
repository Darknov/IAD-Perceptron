#include "NeuralNetwork.h"
#include "Neuron.h"
#include <exception>


NeuralNetwork::NeuralNetwork()
{
	// wczytaj z pliku
	// * ilość warstw
	// * ilość neuronów w każdej warstwie
	// * jakie wagi są przypisane do wyjść każdej z warstw (oprócz ostatniej)
	//		* możemy to zapisać w pliku tekstowym (będzie łatwo edytowalne)
	//		* możemy też zapisać do pliku bezpośrednio liczby (będzie łatwiej 
	//		  dla programu, jeżeli nie musimy ich modyfikować przez notatnik, to super)

	// Nie mogę kontynuować, bo wikampa konserwują >.>

}

void NeuralNetwork::setBias(bool exists)
{
	for (NeuralLayer l : layers)
		l.setBiasPermissions(exists);
}

void NeuralNetwork::setInput(std::vector<double>& input)
{
	int i = 0;
	for (double x : input)
	{
		layers[0].getNeuron(i).setInput(x);
		i++;
	}
}

std::vector<double> NeuralNetwork::getOutput()
{
	return this->output;
}

double NeuralNetwork::getError()
{
	return error;
}

void NeuralNetwork::propagateForward()
{
	for (int i = 0; i < layers.size() - 1; i++)
	{
		std::vector<double> currentLayerOutputs;

		NeuralLayer& currentLayer = layers[i];
		NeuralLayer& nextLayer = layers[i+1];

		for (int j=0; j<currentLayer.getSize(); j++)
		{
			Neuron currentNeuron = currentLayer.getNeuron(j);
			double currentNeuronOutput = currentNeuron.getOutput();
			currentLayerOutputs.push_back(currentNeuronOutput);
		}

		for (int k = 0; k < nextLayer.getSize(); k++)
		{
			Neuron currentNeuron = nextLayer.getNeuron(k);
			currentNeuron.setInput(currentLayerOutputs);
		}

	}
}