#include "AStar.h"

#include <vector>

void AStar::Algorithm()
{
	std::vector<Node> openNodes;
	std::vector<Node> closedNodes;

	Node* goal = new Node { Vector2(50, 75) };
	Node* startNode = new Node { Vector2(0, 0) };

	openNodes.push_back(*startNode);

	while(!openNodes.empty())
	{
		Node* currentNode = &openNodes.front();
		openNodes.erase(openNodes.begin());

		if (currentNode->position == goal->position)
		{
			std::vector<Node*> path;
			while (currentNode)
			{
				path.push_back(currentNode);
				currentNode = currentNode->parent;
			}
			//std::reverse(path.begin(), path.end());
			//return path;
		}

		closedNodes.push_back(*currentNode);
	}
}

float AStar::Heuristic(Node* a, Node* b)
{
	return std::abs(a->position.x - b->position.x) + std::abs(a->position.y - b->position.y);
}
