//#include <vector>
//#include <memory>
#include "perceptron.h"
#include <iostream>



int main() {

	std::shared_ptr<Perceptron> perc = std::make_shared<Perceptron>(
		2,
		1,
		2,
		2,
		0.08,
		Perceptron::SIGMOID,
		Perceptron::SIGMOID);

	std::vector<double> trainingResult;
	int maxEpochs = 10000;
	double meanSquareError = 0.0;

	int inputSets = 4;

	for (int i = 0; i < maxEpochs; i++) {
		for (int j = 0; j < inputSets; j++) {
			std::vector<double> inputs;
			std::vector<double> idealOutputs;

			switch (j) {
			case 0:
				inputs.push_back(0);
				inputs.push_back(0);
				idealOutputs.push_back(0 ^ 0);
				break;
			case 1:
				inputs.push_back(0);
				inputs.push_back(1);
				idealOutputs.push_back(0 ^ 1);
				break;
			case 2:
				inputs.push_back(1);
				inputs.push_back(0);
				idealOutputs.push_back(1 ^ 0);
				break;
			case 3:
				inputs.push_back(1);
				inputs.push_back(1);
				idealOutputs.push_back(1 ^ 1);
				break;
			default:
				break;
			}

			trainingResult = perc->ProcessNetwork(inputs, idealOutputs);

			double error = idealOutputs[0] - trainingResult[0]; // errorline

			double errorSquared = error * error;

			meanSquareError += errorSquared;
		}

		meanSquareError = meanSquareError / inputSets;

		// Checks accuracy.
		// If very accurate, brak loop
		if (meanSquareError < 0.000001) {
			std::cout << "Mean Square Error -> " << meanSquareError << std::endl;
			break;
		}
	}

	std::cout << "Results after training: " << std::endl;
	std::cout << " 0  0  => " << trainingResult.at(0) << std::endl;

	return 0;
}