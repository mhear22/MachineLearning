#pragma once
#include "Header.h"
#include "Node.h"

class Layer 
{
public:
	Layer();
private:
	std::vector<Node*> nodes;
};