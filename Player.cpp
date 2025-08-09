#include <iostream>

#include "Player.h"
#include "Math.h"

void Player::Initialize()
{

}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/Hero.png"))
	{
		std::cout << "Player Images Loaded!" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(0, 400);

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * 16, YIndex * 16, 16, 16));
		sprite.scale(sf::Vector2f(3, 3));
		sprite.setPosition(sf::Vector2f(0, 0));
	}
	else
	{
		std::cout <<"Player image failed to load!" << std::endl;
	}
}

void Player::Update(Enemy& enemy)
{
		sf::Vector2f position = sprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			sprite.setPosition(position - sf::Vector2f(1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			sprite.setPosition(position + sf::Vector2f(1, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			sprite.setPosition(position - sf::Vector2f(0, 1));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			sprite.setPosition(position + sf::Vector2f(0, 1));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
			bullets[bullets.size() - 1].setPosition(sprite.getPosition());
				
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
			bulletDirection = Math::NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	for (size_t i = 0; i < bullets.size(); i++)
	{	
		window.draw(bullets[i]);
	}
}
