#include "Layer.h"

Layer::Layer(int inputNodes)
{
	INPUT_NODE_COUNT = inputNodes;
}

void Layer::AddNode()
{
	nodes.push_back(new Node(INPUT_NODE_COUNT));
}
