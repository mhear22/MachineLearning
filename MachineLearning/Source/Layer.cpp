#include "Layer.h"

Layer::Layer()
{
}

void Layer::AddNode(Node * node)
{
	nodes.push_back(node);
}
