#pragma once

#include "Vector2.h"

struct Node
{
	Node(Vector2 pPosition = Vector2(0,0));
	int GetDistance(Node* from);

	bool operator==(const Node& other) const;

	Node* parent;
	Vector2 position;

	int g, h, f;
};


