#pragma once

#include "Header.h"

class Node 
{
public:
	Node(int ConnectedNodes);
	int Calculate(std::vector<int> input, int count);
	void Update(std::vector<int> weightingsAdjustment);
private:
	std::vector<int> Weightings;
	int CONNECTED_NODES;
};