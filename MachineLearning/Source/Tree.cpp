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
	int DataCount = ReadData(testData);
	BuildLayers(DataCount);
	float currentRMS = 1;
	int count = 0;
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

int Tree::ReadData(string data)
{
	
	return 0;
}

void Tree::BuildLayers(int InputLayerCount)
{
	for (int x = 0; x < LAYER_COUNT; x++)
	{
		Layer* layer = new Layer(InputLayerCount);
		for (int y = 0; y < NODES_PER_LAYER; y++)
		{
			layer->AddNode();
		}
		layers.push_back(layer);
		InputLayerCount = NODES_PER_LAYER;
	}
}
