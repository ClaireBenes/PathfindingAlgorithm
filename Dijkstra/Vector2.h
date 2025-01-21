#pragma once

#include <string>

struct Vector2
{
	Vector2(int x = 0, int y = 0);

	int SqrDistance();
	std::string ToString();

	bool operator==(const Vector2& goal) const;
	Vector2 operator-(const Vector2& vector2) const;

	int x, y;
};

