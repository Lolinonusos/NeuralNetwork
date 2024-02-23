#include "networkLayer.h"

#include "neuron.h"

NetworkLayer::NetworkLayer(int _neuronAmount, int inputsPerNeuron) {
	neuronAmount = _neuronAmount;
	for (int i = 0; i < neuronAmount; i++) {
		std::shared_ptr<Neuron> newNeuron = std::make_shared<Neuron>(inputsPerNeuron);
		neurons.push_back(newNeuron);
	}
}

NetworkLayer::~NetworkLayer() {
}

void NetworkLayer::setNeuronInput(std::vector<double> _inputs) {
	for (int i = 0; i < neuronAmount - 1; i++) {
		neurons[i]->inputs = _inputs;
	}
}

void NetworkLayer::setNeuronOutput(std::vector<double> _outputs) {
	for (int i = 0; i < neuronAmount - 1; i++) {
		neurons[i]->output = _outputs[i];
	}
}

std::vector<double> NetworkLayer::calcNeuronOutput() {
	std::vector<double> output;
	
	for (int i = 0; i < neuronAmount - 1; i++) {
		output.push_back(neurons[i]->calcOutput());
	}

	return output;
}

std::vector<double> NetworkLayer::calcNeuronError(std::vector<double> input) {
	std::vector <double> errorGradVector{};
	
	//for (int i = neurons.size() - 1; i > 0; i++) {
	for (int i = 0; i < neuronAmount - 1; i++) {
		errorGradVector.push_back(neurons[i]->calcErrorGradient(input[i]));
		
	}

	return errorGradVector;
}

void NetworkLayer::updateNeuronWeight(double learningRate, double errorDiff, bool isOutputLayer = false) {
	for (int i = 0; i < neuronAmount; i++) {
		neurons[i]->updateWeight(learningRate, errorDiff, isOutputLayer);
	}
}

void NetworkLayer::updateNeuronBias(double learningRate) {
	for (int i = 0; i < neuronAmount; i++) {
		neurons[i]->updateBias(learningRate);
	}
}
