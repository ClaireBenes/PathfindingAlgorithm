#include "Vector2.h"

#include <iomanip>
#include <sstream>

Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

float Vector2::SqrDistance()
{
	return sqrt(x * x + y * y);
}

std::string Vector2::ToString()
{
	//Round float to .2f and convert it to string
	//for X
	std::stringstream xStream;
	xStream << std::fixed << std::setprecision(0) << x;
	std::string xPos = xStream.str();

	//for Y
	std::stringstream yStream;
	yStream << std::fixed << std::setprecision(0) << y;
	std::string yPos = yStream.str();

	return "(" + xPos + " , " + yPos + ")";
	
}

bool Vector2::operator==(const Vector2& goal) const
{
	return x == goal.x && y == goal.y;
}

Vector2 Vector2::operator-(const Vector2& vector2) const
{
	return Vector2(x - vector2.x, y - vector2.y);
}

Vector2 Vector2::operator+(const Vector2& vector2) const
{
	return Vector2(x + vector2.x, y + vector2.y);
}
