#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>

class Map
{
	private:
		sf::Texture tileSheetTexture;
	
		std::vector<Tile> tiles;

		sf::Vector2i size;

		int tileWidth;
		int tileHeight;
		sf::Vector2f scale;

		int totalTiles;

		int totalTilesX;
		int totalTilesY;

		int mapNumbers[6] =
		{
			1, 1, 1, 4, 4, 1
		};

		sf::Sprite mapSprites[6];

	public:
		Map();
		~Map();

		void Initialize();
		void Load();
		void Update(float deltaTime);
		void Draw(sf::RenderWindow& window);
};
