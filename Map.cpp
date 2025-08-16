#include "Map.h"
#include <iostream>

Map::Map() :
	tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
	if (tileSheetTexture.loadFromFile("Assets/World/Ground Tileset/Tileset_Road.png"))
	{
		totalTilesX = tileSheetTexture.getSize().x / tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;

		std::cout << "Road tileSheet Loaded!" << std::endl;

		for (size_t i = 0; i < 6; i++)
		{
			sprites[i].setTexture(tileSheetTexture);
			sprites[i].setTextureRect(sf::IntRect(i * tileWidth, 0 * tileHeight, tileWidth, tileHeight));
			sprites[i].setScale(sf::Vector2f(3, 3));
			sprites[i].setPosition(sf::Vector2f(i * tileWidth * 3, 0 * tileHeight * 3));
		}

	}
	else
	{
		std::cout <<"Road tileSheet failed to load!" << std::endl;
	}

}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 6; i++)
	{
		window.draw(sprites[i]);
	}
}
