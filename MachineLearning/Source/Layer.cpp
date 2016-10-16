#include "Layer.h"

Layer::Layer(int inputNodes)
{
	INPUT_NODE_COUNT = inputNodes;
}

void Layer::AddNode()
{
	nodes.push_back(new Node(INPUT_NODE_COUNT));
}

vector<int> Layer::Run(vector<int> input)
{
	vector<int> result;
	for each (Node* node in nodes)
	{
		result.push_back(node->Calculate(input));
	}

	return result;
}
