/*****************************************************************************/
/* File includes */
#include <math.h>
#include "pch.h"
#include "neuralNetwork.h"


namespace NeuralNet
{
/*****************************************************************************/
/* NeuralNetwork */
/*****************************************************************************/
#pragma region NeuralNetwork Class
	neuralNetwork::neuralNetwork()
	{

	}
	neuralNetwork::neuralNetwork(neuralNetwork* copy)
	{

	}
	neuralNetwork::~neuralNetwork()
	{
		/* Delete all neurons */

		linkedList_t* currentLayer = (linkedList_t*)getData(getFirstElement(layers));
		for (uint16_t i = 0; i < this->m_number_of_columns; i++)
		{
			if (currentLayer == NULL)
			{
				break;
			}

			link_t* currentLine = searchByNumber(currentLayer, i);

			if (currentLine == NULL)
			{
				continue;
			}

			/* Get neuron in the selected line */
			neuron* n = (neuron*)getData(currentLine);
			
			
			
			n->~neuron();				/* Delete selected neuron */

#ifdef IN_PROGRESS
			std::cout << "Destroyed Neuron " << n->getName()->string;
#endif

			currentLayer = (linkedList_t*)getData(getNextElement(searchByData(layers, currentLayer)));
		}

		/* Delete linked lists */
		deleteLinkedList(layers);
		deleteLinkedList(m_number_of_lines);
	}
#pragma endregion




/*****************************************************************************/
/* Neuron */
/*****************************************************************************/
#pragma region Neuron Class

/*****************************************************************************/
/* Constructors */
#pragma region Constructors
	neuron::neuron(const char* name, int column, int line)
	{
		/* Fill members */
		this->column = column;
		this->line = line;

		/* Create lists */
		this->inputConnections = createLinkedList(sizeof(connection));
		this->outputConnections = createLinkedList(sizeof(connection));

		/* Create string */
		this->m_name = stringConstructor(name);
	}


	neuron::~neuron()
	{
		/* Delete lists */
		deleteLinkedList(this->inputConnections);
		deleteLinkedList(this->outputConnections);

		/* Delete string */
		stringDestructor(&this->m_name);
	}
#pragma endregion


/*****************************************************************************/
/* Public methods */
#pragma region Public methods 
	void neuron::setBias(double bias)
	{
		this->m_bias = bias;
	}

	double neuron::getBias(void)
	{
		return this->m_bias;
	}

	double neuron::getOutput(void)
	{
		return this->m_output;
	}

	string_t* neuron::getName(void)
	{
		return this->m_name;
	}

	double neuron::calculate(void)
	{
		double value;
		value = getAllInputs();
		value = activationFunction(value);

		m_output = value + this->m_bias;
		return m_output;
	}

#pragma endregion


/*****************************************************************************/
/* Private methods */
#pragma region Private methods
	double neuron::activationFunction(double value)
	{
		/* Sigmoid function: */
		/* _____1_____       */
		/*   1 + e^x	     */
		value = exp(value);					/* value = e^x */

		value = 1 / 1 + value;

		return value;
	}

	double neuron::getAllInputs(void)
	{
		return 0.0;
	}
#pragma endregion
#pragma endregion
/* End of neuron */




/*****************************************************************************/
/* Connection */
/*****************************************************************************/
#pragma region Connection Class
/*****************************************************************************/
/* Constructors */
	connection::connection(neuron* input, neuron* output)
	{
		this->inputNeuron = input;
	}


	connection::~connection()
	{
	}

#pragma endregion
/* End of connection */
}