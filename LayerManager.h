#pragma once

#include "LayerOfNeurons.h"
// wpisać jako define nazwy plików
class LayerManager
{
public:
	
	std::vector<LayerOfNeurons> loadLayersFromFile();
	std::vector<LayerOfNeurons> loadRandomLayers();
	std::vector<int> loadPatternsFromFile();
	std::vector<int> loadSomePatternsDunnoWhatsGoingOn();
	void saveLayersToFile(std::vector<LayerOfNeurons>);

	
};

