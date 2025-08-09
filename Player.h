#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
	private:
		sf::Texture texture;

		std::vector<sf::RectangleShape> bullets;
		float bulletSpeed = 0.5f;

	public:
		sf::Sprite sprite;

	public:
		void Initialize();
		void Load();
		void Update(Enemy& enemy);
		void Draw(sf::RenderWindow& window);	
};
