#pragma once

#include "networkLayer.h"

class Perceptron {
public:
	enum ACTIVATION_FUNCTION {
		BINARYSTEP,
		SIGMOID,
		HTAN
	};

	Perceptron(int _numInput,
		int _numOutputNeurons,
		int _numHiddenLayers,
		int _numHiddenLayerNeurons,
		double _learningRate,
		ACTIVATION_FUNCTION _afHiddenLayer,
		ACTIVATION_FUNCTION _afOutputLayer);

	~Perceptron();

	int numInputNeurons{};
	int numOutputNeurons{};
	int numHiddenLayers{};
	int numHiddenLayerNeurons{};
	double learningRate{};

	std::vector<std::shared_ptr<NetworkLayer>> layers;

	std::vector<double> ProcessNetwork(std::vector<double> inputs, std::vector<double> desiredOutputs, bool updateWeight = true);

	void Save();
	void Load();

private:
	ACTIVATION_FUNCTION afHiddenLayer{};
	ACTIVATION_FUNCTION afOutputLayer{};

	void UpdateWeights(std::vector<double> outputs, std::vector<double> desiredOutput);

	double GetActivationFunction(ACTIVATION_FUNCTION function, double x);

	double BinaryStep(double x);
	double Sigma(double x); // Sigmoid
	double HyperBolicTangent(double x); // HTan
};
