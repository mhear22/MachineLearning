#pragma once

#include "Header.h"
#include "Layer.h"

using namespace std;

class Tree
{
public:
	Tree();
	void Test();
	int Run();

	float RMS_ERROR_TARGET;
	int ITERATION_COUNT;
	string testData;
	string testResults;
	string Data;
private:
	float LEARNING_RATE;

	float LAYER_COUNT;
	float NODES_PER_LAYER;

	vector<Layer*> layers;

	float Test(float learningRate);
	int ReadData(string data);
	void BuildLayers(int InputLayerCount);
};