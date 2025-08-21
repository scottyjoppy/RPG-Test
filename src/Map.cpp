#include <iostream>
#include "Map.h"
#include "Math.h"

Map::Map() :
	tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0), totalTiles(0)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
	size = sf::Vector2i(tileWidth, tileHeight);
}

void Map::Load()
{
	if (tileSheetTexture.loadFromFile("assets/world/ground tileset/tileset_road.png"))
	{
		totalTilesX = tileSheetTexture.getSize().x / tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;

		totalTiles = totalTilesX * totalTilesY;

		tiles.resize(totalTiles);

		for (size_t y = 0; y < totalTilesY; y++)
		{
			for (size_t x = 0; x < totalTilesX; x++)
			{
				int i = x + y * totalTilesX;

				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
			}
		}

		std::cout << "Road tileSheet Loaded!" << std::endl;
	}
	else
	{
		std::cout <<"Road tileSheet failed to load!" << std::endl;
	}

	for (size_t y = 0; y < mapHeight; y++)
	{
		for (size_t x = 0; x < mapWidth; x++)
		{
			int i = x + y * mapWidth;

			int index = mapNumbers[i];

			mapSprites[i].setTexture(tileSheetTexture);
			mapSprites[i].setTextureRect(sf::IntRect
					(
					 tiles[index].position.x,
					 tiles[index].position.y,
					 tileWidth,
					 tileHeight
					));

			scale = Math::CalcScale(size);

			mapSprites[i].setScale(sf::Vector2f(scale.x, scale.y));
			mapSprites[i].setPosition(sf::Vector2f(x * tileWidth * mapSprites[i].getScale().x, y * tileHeight * mapSprites[i].getScale().y));
		}
	}

}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < mapSize; i++)
	{
		window.draw(mapSprites[i]);
	}
}
