#pragma once
/*****************************************************************************/
/* File includes */
#include "pch.h"


/*****************************************************************************/
/* Classes */
namespace NeuralNet
{
/*****************************************************************************/
/* Class declarations */
#pragma region Class declarations 
	class neuron;
	class connection;
#pragma endregion


/*****************************************************************************/
/* Neural Network Class declaration */
#pragma region NeuralNetwork
	class neuralNetwork
	{
	/* Methods */
	public:
		/* Constructors */
		neuralNetwork();
		neuralNetwork(neuralNetwork* copy);
		~neuralNetwork();

		/* Layer accessors */
		int getNumberOfLayers();
		int getNumberOfLines(int layer);

	/* Variables */
	public:
		linkedList_t* layers;

	/* Methods */
	private:

	/* Variables */
	private:
		linkedList_t* m_number_of_lines;
		uint16_t m_number_of_columns;
	};
#pragma endregion


/*****************************************************************************/
/* Neuron Class declaration */
#pragma region Neuron
	class neuron
	{
		/* Methods */
	public:
		neuron(const char* name, int column, int line);
		~neuron();

		void addInputConnection(connection connection);
		void addOutputConnection(connection connection);

		void setBias(double bias);
		double getBias(void);

		double getOutput(void);
		string_t* getName(void);

		double calculate(void);
		/* Variables */
	public:
		int column;
		int line;

		linkedList_t* inputConnections;
		linkedList_t* outputConnections;

		/* Methods */
	private:
		double activationFunction(double value);
		double getAllInputs(void);
		/* Variables */
	private:
		double m_bias;
		double m_output;
		double m_input;
		string_t* m_name;
	};
#pragma endregion


/*****************************************************************************/
/* Connection Class declaration */
#pragma region Connection
	class connection
	{
	/* Methods */
	public:
		connection(neuron* input, neuron* output);
		~connection();

	/* Variables */
	public:
		neuron* inputNeuron;
		neuron* outputNeuron;
	};

#pragma endregion
}