#pragma once

#include "Vector2.h"

struct Node
{
	Node(Vector2 pPosition = Vector2());
	int GetDistance(Node* from);

	Node* parent;
	Vector2 position;
	int costFromStart, heuristic, totalCost;
};


