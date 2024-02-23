#include "neuron.h"
#include <random>
#include <iostream>

Neuron::Neuron(int _inputAmount) {
	inputAmount = _inputAmount;

	for (int i = 0; i < inputAmount; i++) {
		//inputs.push_back(0);
		weights.push_back(randomDouble(-1, 1));
	}

	bias = randomDouble(-1, 1);

}

Neuron::~Neuron() {
}

double Neuron::randomDouble(double min, double max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(min, max);

	return dis(gen);
}

double Neuron::calcOutput() {
	
	double toOutput{};
	for (int i = 0; i < inputAmount; i++) {
		toOutput += inputs[i] * weights[i];
	}

	toOutput += bias;

	N = toOutput;

	toOutput = GetActivationFunction(0, toOutput);
	output = toOutput;

	return toOutput;
}

double Neuron::calcErrorGradient(double idealOutput) {
	
	// For neurons in output layer
	double errorDifference = idealOutput - output;
	errorGradient = errorDifference * GetActivationFunctionDerivative(0, output);

	return errorGradient;
}

void Neuron::updateWeight(double learningRate, double errorDiff, bool isOutputLayer) {
	std::vector<double> prevWeights = weights;

	double error = errorGradient;
	if (isOutputLayer) {
		error = errorDiff;
	}

	for (int i = 0; i < weights.size() - 1; i++) {
		weights[i] = prevWeights[i] + learningRate * output * error;
	}
}

void Neuron::updateBias(double learningRate) {
	double prevBias = bias;

	bias = prevBias + learningRate * output * errorGradient;
}

double Neuron::GetActivationFunction(int function, double x) {
	double result = 0.0;

	switch (function) {
	case 0:
		result = BinaryStep(x);
		break;
	case 1:
		result = Sigma(x);
		break;
	case 2:
		result = HyperBolicTangent(x);
		break;
	default:
		// Error, defaulting to binaryStep
		std::cout << "\n!!! Error, defaulting to binaryStep !!!\n" << std::endl;
		result = BinaryStep(x);
		break;
	}
	return result;
}

double Neuron::GetActivationFunctionDerivative(int function, double x) {
	double result = 0.0;

	switch (function) {
	case 0:
		result = BinaryStepDerivative();
		break;
	case 1:
		result = SigmaDerivative(x);
		break;
	case 2:
		result = HyperBolicTangentDerivative(x);
		break;
	default:
		// Error, defaulting to binaryStep
		std::cout << "\n!!! Error, defaulting to binaryStep !!!\n" << std::endl;
		result = BinaryStepDerivative();
		break;
	}
	return result;
}

double Neuron::BinaryStep(double x) {
	if (x > 0.0) {
		return 1.0;
	}
	return 0.0;
}

double Neuron::BinaryStepDerivative() {
	return 0.0;
}

double Neuron::Sigma(double x) {
	if (x >= 45.0) {
		return 1.0;
	}
	else if (x <= 45.0) {
		return 0.0;
	}
	return 1.0 / (1.0 + exp(-x));
}

double Neuron::SigmaDerivative(double x) {
	return x * (1 - x);
}

double Neuron::HyperBolicTangent(double x) {
	return 1.0 - x * x;
}

double Neuron::HyperBolicTangentDerivative(double x) {
	return 1.0 - pow(x, 2);
}

void Neuron::Save() {
}

void Neuron::Load() {
}
