#pragma once

#include "Vector2.h"

struct Node
{
	Node(Vector2 pPosition = Vector2(0,0));
	float GetDistance(Node* from);

	Node* parent;
	Vector2 position;

	float g, h, f;
	float costMultiplier;
};


