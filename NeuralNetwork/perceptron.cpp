#include "perceptron.h"
#include "neuron.h"


#include <iostream>

Perceptron::Perceptron(int _numInputNeurons, int _numOutputNeurons, int _numHiddenLayers, int _numHiddenLayerNeurons, double _learningRate, ACTIVATION_FUNCTION _afHiddenLayer, ACTIVATION_FUNCTION _afOutputLayer) {
	numInputNeurons = _numInputNeurons;
	numOutputNeurons = _numOutputNeurons;
	numHiddenLayerNeurons = _numHiddenLayerNeurons;
	numHiddenLayers = _numHiddenLayers;
	afHiddenLayer = _afHiddenLayer;
	afOutputLayer = _afOutputLayer;

	int inputsPerNeuron = 1;

	// Input layer
	std::shared_ptr<NetworkLayer> newLayer = std::make_shared<NetworkLayer>(numInputNeurons, inputsPerNeuron);
	layers.push_back(newLayer);

	inputsPerNeuron = numInputNeurons;

	// Hidden layers
	for (int i = 0; i < numHiddenLayers; i++) {
		newLayer = std::make_shared<NetworkLayer>(numHiddenLayerNeurons, inputsPerNeuron);
		layers.push_back(newLayer);
		inputsPerNeuron = numHiddenLayerNeurons;
	}

	//inputsPerNeuron = numHiddenLayerNeurons;
	if (inputsPerNeuron <= 0) {
		inputsPerNeuron = 1;
	}


	// Output layer
	newLayer = std::make_shared<NetworkLayer>(numHiddenLayerNeurons, inputsPerNeuron);
	layers.push_back(newLayer);

	newLayer.~shared_ptr();
}

Perceptron::~Perceptron() {
}

std::vector<double> Perceptron::ProcessNetwork(std::vector<double> _inputs, std::vector<double> desiredOutputs, bool updateWeight) {
	int totalLayer = layers.size();

	std::vector<double> inputs = _inputs;

	std::vector<double> outputVector;
	double tempOutput = 0;
	
	for (int i = 0; i < totalLayer; i++) {
		layers[i]->setNeuronInput(inputs);
		outputVector = layers[i]->calcNeuronOutput();

		/*for (int skruf = 0; skruf < outputVector.size() - 1; skruf++) {
			outputVector[i] = GetActivationFunction(afHiddenLayer, outputVector[i]);
		}*/
		//layers[i]->setNeuronOutput(outputVector);

		inputs = outputVector;

		//for (int j = 0; j < layers[i]->neurons.size() - 1; j++) {
		//	layers[i]->neurons[j];
		//	for (int k = 0; k < layers[i + 1]->neurons.size() - 1; k++) {
		//	}
		//}
		std::cout << "##### Layer " << i << " processed #####\n" << std::endl;
		
	}

	std::vector<double> temp = desiredOutputs;
	// Calculate error gradient of output layer
	//layers[totalLayer]->calcNeuronError(desiredOutputs);

	// Backpropogation
	for (int i = totalLayer; i >= 0; i--) {
		temp = layers[i]->calcNeuronError(temp);
		// Errorgradient sum
		for (int j = 0; j < layers[i]->neuronAmount; j++) {
			for (int k = 0; k < layers[i]->neurons[j]->weights.size(); k++) {
				layers[i]->errorGradSum += layers[i]->neurons[j]->errorGradient * layers[i]->neurons[j]->weights[k];
			}
		}
		layers[i]
	}

	//layers[layers.size() - 1]->
	
	return outputVector;
}

void Perceptron::UpdateWeights(std::vector<double> outputs, std::vector<double> desiredOutput) {
	


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
