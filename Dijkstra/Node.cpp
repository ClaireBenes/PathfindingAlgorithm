#include "Node.h"

#include <limits>
#define inf std::numeric_limits<int>::max()

Node::Node(Vector2 pPosition) : position(pPosition)
{
	costFromStart = inf;
	heuristic = inf;
	totalCost = inf;

	parent = nullptr;
}

int Node::GetDistance(Node* from)
{
	return ( position - from->position ).SqrDistance();
}
