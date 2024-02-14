#pragma once

#include "neuron.h"
#include <memory>

class NetworkLayer {
public:
	NetworkLayer(int neuronAmount, int value);
	~NetworkLayer();

	std::vector<std::shared_ptr<Neuron>> neurons;

	void Save();
	void Load();
};

