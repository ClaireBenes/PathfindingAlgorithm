#pragma once

#include "Node.h"

#include <vector>

class AStar
{
public:
	void Algorithm(const std::vector<std::vector<float>>& grid, Vector2 start, Vector2 goal);

	std::vector<Node*> GetChildrens(Node* current, const std::vector<std::vector<float>>& grid);

	float Heuristic(Node* a, Node* b);
	void CleanupNodes(std::vector<Node*>& nodes);
};

