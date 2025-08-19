#include <math.h>
#include "Math.h"
#include <iostream>

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector)
{
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	if (m == 0.0f || m < 0.0001f)
	{
		std::cout << "Trying to divide by 0 Math.cpp" << std::endl;
		return sf::Vector2f(1.0f, 0.0f);
	}

	sf::Vector2f normalizedVector;

	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

bool Math::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2)
{
	if (
			rect1.left + rect1.width > rect2.left &&
			rect2.left + rect2.width > rect1.left &&
			rect2.top + rect2.height > rect1.top &&
			rect1.top + rect1.height > rect2.top
	   )
		return true;
	return false;
}

sf::Vector2f Math::CalcScale(sf::Vector2i tileSize)
{
	// Set 48 pixels per tile as standard
	float defaultSize = 48;

	sf::Vector2f size;

	if (tileSize.x > tileSize.y)
	{
		size.x = defaultSize / tileSize.x;
		size.y = defaultSize / tileSize.x;
	}
	else
	{
		size.x = defaultSize / tileSize.y;
		size.y = defaultSize / tileSize.y;
	}

	return size;
 }
