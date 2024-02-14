#pragma once

#include "networkLayer.h"

class Perceptron {
public:
	enum ACTIVATION_FUNCTION {
		BINARYSTEP,
		SIGMOID,
		HTAN
	};

	Perceptron(int input, 
		int output, 
		int hiddenLayer,
		int hiddenLayerAmount,
		int neuronsPerLayer, 
		double learningRate, 
		ACTIVATION_FUNCTION af, 
		ACTIVATION_FUNCTION afOut);

	~Perceptron();

	std::vector<double> Train(std::vector<double> inputs, std::vector<double> desiredOutputs, bool updateWeight = true);

	void Save();
	void Load();

private:
	ACTIVATION_FUNCTION afHiddenLayer;
	ACTIVATION_FUNCTION afOutputLayer;

	void UpdateWeights();

	double GetActivationFunction(ACTIVATION_FUNCTION function, double x);

	double BinaryStep(double x);
	double Sigma(double x); // Sigmoid
	double HyperBolicTangent(double x); // HTan
};
