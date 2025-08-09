#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	sf::Vector2f normalizedVector;

	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main()
{
	//-----INITIALIZE-----
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
	//-----INITIALIZE-----

	//-----LOAD-----
	
	//-----ENEMY-----
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	if (enemyTexture.loadFromFile("Assets/Enemy/Textures/Enemy.png"))
	{
		std::cout << "Enemy Images Loaded!" << std::endl;
		enemySprite.setTexture(enemyTexture);
		enemySprite.setPosition(600, 400);

		int XIndex = 0;
		int YIndex = 3;

		enemySprite.setTextureRect(sf::IntRect(XIndex * 96, YIndex * 96, 96, 96));
		enemySprite.scale(sf::Vector2f(0.5, 0.5));
	}
	else
	{
		std::cout <<"Enemy image failed to load!" << std::endl;
	}
	//-----ENEMY-----

	//-----HERO-----
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/Hero.png"))
	{
		std::cout << "Player Images Loaded!" << std::endl;
		playerSprite.setTexture(playerTexture);
		playerSprite.setPosition(0, 400);

		int XIndex = 0;
		int YIndex = 0;

		playerSprite.setTextureRect(sf::IntRect(XIndex * 16, YIndex * 16, 16, 16));
		playerSprite.scale(sf::Vector2f(3, 3));
	}
	else
	{
		std::cout <<"Player image failed to load!" << std::endl;
	}
	//-----HERO-----
	
	//-----LOAD-----
	
	//-----CALC BULLET DIRECTION-----
	sf::RectangleShape bullet(sf::Vector2f(50, 20));
	bullet.setPosition(playerSprite.getPosition());

	sf::Vector2f direction = enemySprite.getPosition() - bullet.getPosition();
	direction = NormalizeVector(direction);

	//-----CALC BULLET DIRECTION-----


	//-----GAME LOOP-----
	while (window.isOpen())
	{	

		//-----UPDATE-----
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}	

		bullet.setPosition(bullet.getPosition() + direction);

		sf::Vector2f position = playerSprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(position - sf::Vector2f(1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(position - sf::Vector2f(0, 1));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));
		//-----UPDATE-----
		
		//-----DRAW-----
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(enemySprite);
		window.draw(bullet);
		window.display();
		//-----DRAW-----
	}

	return 0;
}
