#include "AStar.h"

#include <vector>

void AStar::Algorithm()
{
	std::vector<Node> openNodes;
	std::vector<Node> closedNodes;

	Node startNode;
	openNodes.push_back(startNode);

	while(!openNodes.empty())
	{
		Node* currentNode;
		for(Node &node : openNodes)
		{
			if(node.totalCost < currentNode->totalCost)
			{
				currentNode = &node;
			}
		}

		auto it = std::find(openNodes.begin(), openNodes.end(), currentNode);
		openNodes.erase(it);
	}
}
