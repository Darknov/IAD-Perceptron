#pragma once

#include "NeuronLayer.h"
// wpisać jako define nazwy plików
class LayerManager
{
public:
	
	std::vector<NeuronLayer> loadLayersFromFile();
	std::vector<NeuronLayer> loadRandomLayers();
	std::vector<int> loadPatternsFromFile();
	std::vector<int> loadSomePatternsDunnoWhatsGoingOn();
	void saveLayersToFile(std::vector<NeuronLayer>);

	
};

