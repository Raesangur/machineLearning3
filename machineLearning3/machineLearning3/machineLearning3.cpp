#include <iostream>
#include "pch.h"
#include "neuralNetwork.h"

int main()
{
	NeuralNet::neuralNetwork newNeuralNet = new NeuralNet::neuralNetwork;

	newNeuralNet.~neuralNetwork();


    std::cout << "Hello World!\n"; 

	std::cin.get();
}