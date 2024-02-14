#include "perceptron.h"

Perceptron::Perceptron(int input, int output, int hiddenLayer, int hiddenLayerAmount, int neuronsPerLayer, double learningRate, ACTIVATION_FUNCTION af, ACTIVATION_FUNCTION afOut) {
	
}

Perceptron::~Perceptron() {
}

double Perceptron::GetActivationFunction(ACTIVATION_FUNCTION function, double x) {
	double result  = 0.0;

	switch (function) {
	case Perceptron::BINARYSTEP:
		result = BinaryStep(x);
		break;
	case Perceptron::SIGMOID:
		result = Sigma(x);
		break;
	case Perceptron::HTAN:
		result = HyperBolicTangent(x);
		break;
	default:
		// Error
		result = -1.0;
		break;
	}
	return result;
}

double Perceptron::BinaryStep(double x) {
	if (x > 0.0) {
		return 1.0;
	}
	return 0.0;
}

double Perceptron::Sigma(double x) {
	if (x >= 45.0) {
		return 1.0;
	}
	else if (x <= 45.0) {
		return 0.0;
	}
	return 1.0 / (1.0 + exp(-x));
}

double Perceptron::HyperBolicTangent(double x) {
	return 1.0 - x * x;
}
