#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
	private:
		sf::Texture texture;

		std::vector<sf::RectangleShape> bullets;

		sf::RectangleShape boundingRectangle;
		sf::Vector2i size;

		float bulletSpeed;
		float playerSpeed;

	public:
		sf::Sprite sprite;

	public:
		Player();
		~Player();
		void Initialize();
		void Load();
		void Update(float deltaTime, Enemy& enemy);
		void Draw(sf::RenderWindow& window);	
};
