#pragma once

#include <vector> 
#include <memory>

class Edge;

class Neuron {
public:
	Neuron(int _inputAmount);
	~Neuron();

	double randomDouble(double min, double max);

	double calcOutput();
	double calcErrorGradient(double input);

	void updateWeight(double learningRate, double errorDiff, bool isOutputLayer);

	void updateBias(double learningRate);

	double GetActivationFunction(int function, double x);

	double GetActivationFunctionDerivative(int function, double x);

	double BinaryStep(double x); 
	
	double BinaryStepDerivative();

	double Sigma(double x);

	double SigmaDerivative(double x);

	double HyperBolicTangent(double x);

	double HyperBolicTangentDerivative(double x);

	int inputAmount{};
	double bias{};
	double output{};
	double errorGradient{};
	double N{}; // Net input

	std::vector<double> inputs; // Inputs to be received, amount is same as amount of neurons in previous layer
	std::vector<double> weights; // Weights, amount is same as amount of inputs

	std::vector<std::shared_ptr<Edge>> next;

	void Save();
	void Load();
};
