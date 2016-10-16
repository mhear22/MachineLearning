#include "Tree.h"

Tree::Tree()
{
	RMS_ERROR_TARGET = 0.1;
	ITERATION_COUNT = 0;
	
	LEARNING_RATE = 0.01;

	LAYER_COUNT = 3;
	NODES_PER_LAYER = 3;

	InputLayerCount = 0;
}

void Tree::Test()
{
	for each (auto item in testFiles)
	{
		ReadData(item);
	}
	BuildLayers(InputLayerCount);

	float currentRMS = 1;
	int count = 0;
	for (int i = 0; i < testData.size(); i++)
	{
		if (currentRMS > RMS_ERROR_TARGET)
		{
			RunOnce(testData[i]);
			

		}

	}
		//Run once
		//Test RMS
		//Update RMS
}

float Tree::GetRMS(vector<int> dataset, string result)
{
	return 0.0f;
}

float Tree::Update(vector<int> dataset, string result, float learningRate)
{
	return 0.0f;
}

int Tree::Run()
{
	auto x  = ReadData(Data);
	RunOnce(x);
	//Run once
	//Return value
	return 0;
}

vector<int> Tree::RunOnce(vector<int> dataset)
{
	vector<int> previousLayer = dataset;
	for (int i = 0; i < layers.size(); i++)
	{
		previousLayer = layers.at(i)->Run(previousLayer);
	}

	return previousLayer;
}



vector<int> Tree::ReadData(string data)
{
	fstream stream;

	stream.open(data);
	vector<int> result;
	char x[12];

	if (stream.is_open())
	{
		while (!stream.eof())
		{
			stream >> x;
			for (int i = 0; i < 12; i++)
			{
				result.push_back(x[i] == '*');
			}
		}
	}

	auto size = 12 * result.size();

	if (InputLayerCount == 0)
	{
		InputLayerCount = size;
	}

	if (InputLayerCount != size)
	{
		throw "Incompatable";
	}


	InputLayerCount = size;

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
