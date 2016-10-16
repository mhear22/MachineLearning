#pragma once

#include "Header.h"

class Node 
{
public:
	Node(int ConnectedNodes);
	int Calculate(std::vector<int> input);
	void Update(std::vector<int> weightingsAdjustment);
	void Update(float activationWeight);
private:
	std::vector<int> Weightings;
	int CONNECTED_NODES;
	float activationWeight;
};