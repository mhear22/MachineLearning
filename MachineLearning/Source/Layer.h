#pragma once
#include "Header.h"
#include "Node.h"

class Layer 
{
public:
	Layer(int inputNodes);
	void AddNode();
private:
	std::vector<Node*> nodes;
	int INPUT_NODE_COUNT;
};