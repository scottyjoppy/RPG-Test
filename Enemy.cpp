#include "Enemy.h"
#include <iostream>

void Enemy::Initialize()
{

}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/Enemy/Textures/Enemy.png"))
	{
		std::cout << "Enemy Images Loaded!" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(600, 400);

		int XIndex = 0;
		int YIndex = 3;

		sprite.setTextureRect(sf::IntRect(XIndex * 96, YIndex * 96, 96, 96));
		sprite.scale(sf::Vector2f(0.5, 0.5));
	}
	else
	{
		std::cout <<"Enemy image failed to load!" << std::endl;
	}

}

void Enemy::Update()
{

}


void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
