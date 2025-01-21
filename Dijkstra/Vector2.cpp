#include "Vector2.h"

Vector2::Vector2(int x, int y) : x(x), y(y)
{
}

int Vector2::SqrDistance()
{
	return sqrt(x * x + y * y);
}

std::string Vector2::ToString()
{
	return "(" + std::to_string(x) + " , " + std::to_string(y) + ")";
}

bool Vector2::operator==(const Vector2& goal) const
{
	return x == goal.x && y == goal.y;
}

Vector2 Vector2::operator-(const Vector2& vector2) const
{
	return Vector2(x - vector2.x, y - vector2.y);
}
