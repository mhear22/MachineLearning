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
	vector<string> testFiles;

	string testResults;
	string Data;
private:
	float LEARNING_RATE;
	int InputLayerCount;
	float LAYER_COUNT;
	float NODES_PER_LAYER;

	vector<Layer*> layers;
	vector<string> results;
	vector<vector<int>> testData;
	
	vector<int> RunOnce(vector<int> dataset);
	float GetRMS(vector<int> dataset, string result);
	float Update(vector<int> dataset, string result, float learningRate);

	vector<int> ReadData(string data);
	void BuildLayers(int InputLayerCount);
};