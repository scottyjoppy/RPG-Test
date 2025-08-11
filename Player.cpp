#include <iostream>

#include "Player.h"
#include "Math.h"

void Player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(16, 16);
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/Hero.png"))
	{
		std::cout << "Player Images Loaded!" << std::endl;
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(0, 0));

		sprite.scale(sf::Vector2f(3, 3));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		std::cout <<"Player image failed to load!" << std::endl;
	}
}

void Player::Update(float deltaTime, Enemy& enemy)
{
		sf::Vector2f position = sprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			sprite.setPosition(position - sf::Vector2f(1, 0) * playerSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			sprite.setPosition(position - sf::Vector2f(0, 1) * playerSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
			bullets[bullets.size() - 1].setPosition(sprite.getPosition());
				
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
			bulletDirection = Math::NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
		}

		boundingRectangle.setPosition(sprite.getPosition());

		/*if (Math::DidRectCollide(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds()))
			std::cout << "Collision" << std::endl;
		else
			std::cout << "No Collision" << std::endl;
		*/
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{	
		window.draw(bullets[i]);
	}
}
