#pragma once

#include <vector> 

class Neuron {
public:
	Neuron(int input);
	~Neuron();

	int inputValue;
	double bias;
	double output;
	double error;
	double N;

	std::vector<double> weights;
	std::vector<double> inputs;

	void Save();
	void Load();
};
