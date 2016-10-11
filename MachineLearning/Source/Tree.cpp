#include "Tree.h"

Tree::Tree()
{
	RMS_ERROR_TARGET = 0.1;
	ITERATION_COUNT = 0;
	
	LEARNING_RATE = 0.01;

	LAYER_COUNT = 3;
	NODES_PER_LAYER = 3;
}

void Tree::Test()
{
	float currentRMS = 1;
	while (currentRMS > RMS_ERROR_TARGET)
	{
		currentRMS = Test(LEARNING_RATE);
	}
}

int Tree::Run()
{
	return 0;
}

float Tree::Test(float learningRate)
{
	return 0.0f;
}

void Tree::BuildLayers()
{
	for (int x = 0; x < LAYER_COUNT; x++)
	{
		Layer* layer = new Layer();
		for (int y = 0; y < NODES_PER_LAYER; y++)
		{
			layer->AddNode(new Node());
		}
		layers.push_back(layer);
	}
}
