#pragma once

#include <string>

struct Vector2
{
	Vector2(float x = 0, float y = 0);

	float SqrDistance();
	std::string ToString();

	bool operator==(const Vector2& goal) const;
	Vector2 operator-(const Vector2& vector2) const;
	Vector2 operator+(const Vector2& vector2) const;

	float x, y;
};

