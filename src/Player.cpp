#include <iostream>

#include "Player.h"
#include "Math.h"

Player::Player() :
	playerSpeed(1.0f), maxFireRate(150), fireRateTimer(0), tileWidth(40), tileHeight(48)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(tileWidth, tileHeight);
}

void Player::Load()
{
	if (texture.loadFromFile("assets/player/textures/character_idle.png"))
	{
		std::cout << "Player Images Loaded!" << std::endl;
		sprite.setTexture(texture);

		int XIndex = 3;
		int YIndex = 3;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(0, 0));

		scale = Math::CalcScale(size);

		sprite.setScale(sf::Vector2f(scale.x, scale.y));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		std::cout <<"Player image failed to load!" << std::endl;
	}
}

void Player::Update(float deltaTime, Enemy& enemy, sf::Vector2f& mousePosition)
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

		//-------------------------------------------------
		fireRateTimer += deltaTime;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
		{
			bullets.push_back(Bullet());
			int i = bullets.size() - 1;

			bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);

			fireRateTimer = 0;
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].Update(deltaTime);

			if (enemy.health > 0)
			{
				if (Math::DidRectCollide(bullets[i].GetGlobalBounds(), enemy.sprite.getGlobalBounds()))
				{
					enemy.ChangeHealth(-10);
					bullets.erase(bullets.begin() + i);
				}
			}
		}

		boundingRectangle.setPosition(sprite.getPosition());

		//-------------------------------------------------
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{	
		bullets[i].Draw(window);
	}
}
