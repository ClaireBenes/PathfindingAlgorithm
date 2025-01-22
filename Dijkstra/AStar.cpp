#include "AStar.h"

#include <vector>

void AStar::Algorithm(const std::vector<std::vector<int>>& grid, Vector2 start, Vector2 goal)
{
	std::vector<Node*> openNodes;
	std::vector<Node*> closedNodes;

	Node* startNode = new Node(start);
	Node* goalNode = new Node(goal);

	startNode->g = 0;
	startNode->h = Heuristic(startNode, goalNode);
	startNode->f = startNode->g + startNode->h;
	openNodes.push_back(startNode);

	while(!openNodes.empty())
	{
		// Find the node with the lowest f
		Node* currentNode = openNodes[0];
		int lowestFIndex = 0;

		for (int i = 0; i < openNodes.size(); ++i)
		{
			if (openNodes[i]->f < currentNode->f)
			{
				currentNode = openNodes[i];
				lowestFIndex = i;
			}
		}

		// Remove the current node from openNodes
		openNodes.erase(openNodes.begin() + lowestFIndex);

		// Check if we reached the goal
		if (currentNode->position == goalNode->position)
		{
			std::vector<Node*> path;
			while (currentNode)
			{
				path.push_back(currentNode);
				currentNode = currentNode->parent;
			}

			std::reverse(path.begin(), path.end());

			// Output the path
			printf("Path found:\n");
			for (Node* node : path)
			{
				printf("%s", node->position.ToString().c_str());
			}

			// Clean up dynamically allocated nodes
			CleanupNodes(openNodes);
			CleanupNodes(closedNodes);
			return;
		}

		// Add current node to closedNodes
		closedNodes.push_back(currentNode);

		// Check child
		for (Node* child : GetChildrens(currentNode,grid))
		{
			// If child is in closedNodes, skip it
			if (std::find(closedNodes.begin(), closedNodes.end(), child) != closedNodes.end())
			{
				delete child;
				continue;
			}

			// Calculate g, h, and f values
			child->g = currentNode->g + currentNode->GetDistance(child);
			child->h = Heuristic(child, goalNode);
			child->f = child->g + child->h;

			// Check if the child is in the open list
			auto children = std::find(openNodes.begin(), openNodes.end(), child);

			if (children != openNodes.end()) // Already in open list
			{
				if (child->g >= (*children)->g)
				{
					delete child;
					continue;
				}
				else // Better path found, update the node
				{
					(*children)->g = child->g;
					(*children)->f = child->f;
					(*children)->parent = currentNode;
					delete child;
				}
			}
			else // Add the child to the open list
			{
				child->parent = currentNode;
				openNodes.push_back(child);
			}
		}
	}

	// No path found
	printf("No Path found !\n");

	// Clean up dynamically allocated nodes
	CleanupNodes(openNodes);
	CleanupNodes(closedNodes);
}

// GetChildrens function for grid
std::vector<Node*> AStar::GetChildrens(Node* current, const std::vector<std::vector<int>>& grid)
{
	std::vector<Node*> childrens;

	const std::vector<Vector2> directions = 
	{
		Vector2(0, -1), // Up
		Vector2(0, 1),  // Down
		Vector2(-1, 0), // Left
		Vector2(1, 0)   // Right
	};

	for (const Vector2& dir : directions)
	{
		Vector2 newPos = current->position + dir;

		// Check bounds
		if (newPos.x >= 0 && newPos.x < grid.size() &&
			newPos.y >= 0 && newPos.y < grid[0].size())
		{
			// Check if the position is walkable (not an obstacle)
			if (grid[newPos.x][newPos.y] == 0) // Assuming 0 is walkable and 1 is an obstacle
			{
				childrens.push_back(new Node(newPos));
			}
		}
	}

	return childrens;
}

// Heuristic Function: Manhattan Distance
float AStar::Heuristic(Node* a, Node* b)
{
	return std::abs(a->position.x - b->position.x) + std::abs(a->position.y - b->position.y);
}


// Cleanup Function
void AStar::CleanupNodes(std::vector<Node*>& nodes)
{
	for (Node* node : nodes)
	{
		delete node;
	}
	nodes.clear();
}
