#include "networkLayer.h"

NetworkLayer::NetworkLayer(int neuronAmount, int value) {
	for (int i = 0; i < neuronAmount; i++) {
		std::shared_ptr<Neuron> newNeuron = std::make_shared<Neuron>(value);
		neurons.push_back(newNeuron);
	}
}

NetworkLayer::~NetworkLayer() {
}
