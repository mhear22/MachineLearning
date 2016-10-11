#pragma once
#include "Header.h"
#include "Node.h"

class Layer 
{
public:
	Layer();
	void AddNode(Node* node);
private:
	std::vector<Node*> nodes;
};