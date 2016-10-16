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
	vector<int>* DataCount = ReadData(testData);
	BuildLayers(DataCount->size());

	float currentRMS = 1;
	int count = 0;
	while (currentRMS > RMS_ERROR_TARGET)
	{
		//Run once
		//Test RMS
		//Update RMS
	}
}

int Tree::Run()
{
	//Run once
	//Return value
	return 0;
}

vector<int>* Tree::ReadData(string data)
{
	fstream stream;

	stream.open(data);
	vector<int>* result;
	char x[12];

	if (stream.is_open())
	{
		while (!stream.eof())
		{
			stream >> x;
			for (int i = 0; i < 12; i++)
			{
				result->push_back(x[i] == '*');
			}
		}
	}

	stream.close();

	return result;
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
