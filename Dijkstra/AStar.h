#pragma once

#include "Node.h"

class AStar
{
public:
	void Algorithm();
	float Heuristic(Node* a, Node* b);
};

