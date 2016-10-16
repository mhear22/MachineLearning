#pragma once
#include "Header.h"
#include "Node.h"

using namespace std;

class Layer 
{
public:
	Layer(int inputNodes);
	void AddNode();
	vector<int> Run(vector<int> input);
private:
	std::vector<Node*> nodes;
	int INPUT_NODE_COUNT;
};