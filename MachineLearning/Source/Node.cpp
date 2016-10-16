#include "Node.h"

Node::Node(int ConnectedNodes)
{
	CONNECTED_NODES = ConnectedNodes;

	for (int i = 0; i < CONNECTED_NODES; i++)
	{
		Weightings.push_back(rand());
	}

}

int Node::Calculate(std::vector<int> input)
{
	int weight = 0;

	for (int i = 0; i < input.size(); i++)
	{
		weight += Weightings.at(i) * input.at(i);
	}

	return activationWeight * weight;
}

void Node::Update(std::vector<int> weightingsAdjustment)
{
	Weightings = weightingsAdjustment;
}

void Node::Update(float activationWeight)
{
	activationWeight = activationWeight;
}
