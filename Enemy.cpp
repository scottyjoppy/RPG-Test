#include "Enemy.h"
#include <iostream>

Enemy::Enemy() :
	health(100)
{
}

Enemy::~Enemy()
{
}

void Enemy::ChangeHealth(int hp)
{
	health += hp;
	healthText.setString(std::to_string(health));
}

void Enemy::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Yellow);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(96, 96);
}

void Enemy::Load()
{
	if (font.loadFromFile("Assets/Fonts/consola.ttf"))
	{
		std::cout << "Consola Font loaded successfully" << std::endl;
		healthText.setFont(font);
		healthText.setString(std::to_string(health));
	}

	if (texture.loadFromFile("Assets/Enemy/Textures/Enemy.png"))
	{
		std::cout << "Enemy Images Loaded!" << std::endl;
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 3;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(500, 500));

		sprite.scale(sf::Vector2f(0.5, 0.5));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		std::cout <<"Enemy image failed to load!" << std::endl;
	}

}

void Enemy::Update(float deltaTime)
{
	if (health > 0)
	{
		boundingRectangle.setPosition(sprite.getPosition());
		healthText.setPosition(sprite.getPosition());
	}
}


void Enemy::Draw(sf::RenderWindow& window)
{
	if (health > 0)
	{
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthText);
	}
}
