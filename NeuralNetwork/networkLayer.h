#pragma once

#include <vector>
#include <memory>

class Neuron;

class NetworkLayer {
public:
	NetworkLayer(int neuronAmount, int inputsPerNeuron);
	~NetworkLayer();

	std::vector<std::shared_ptr<Neuron>> neurons;
	int neuronAmount;

	void setNeuronInput(std::vector<double> inputs);

	void setNeuronOutput(std::vector<double> _outputs);

	std::vector<double> calcNeuronOutput();

	std::vector<double> calcNeuronError(std::vector<double> idealOutput);

	// Error difference for output layer, gradient for all other layers
	void updateNeuronWeight(double learningRate, double errorDiff, bool isOutputLayer);

	void updateNeuronBias(double learningRate);

	double errorGradSum{};

	void Save();
	void Load();
};

