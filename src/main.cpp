#include <SFML/Graphics.hpp>
#include <iostream>

#include "FrameRate.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "MapLoader.h"

int main()
{
	//-----INITIALIZE-----
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	//-----INITIALIZE-----
	
	FrameRate frameRate;
	Map map;
	Player player;
	Enemy enemy;
	MapLoader mapLoader;
	mapLoader.Load("assets/world/maps/level1.rmap");

	frameRate.Initialize();
	map.Initialize();
	player.Initialize();
	enemy.Initialize();

	//-----INITIALIZE-----
	
	//-----LOAD-----
	
	frameRate.Load();
	map.Load();
	player.Load();
	enemy.Load();	

	//-----LOAD-----

	//-----GAME LOOP-----
	
	sf::Clock clock;

	while (window.isOpen())
	{	
		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
		
		//-----UPDATE-----
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}	

		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

		frameRate.Update(deltaTime);
		map.Update(deltaTime);
		enemy.Update(deltaTime);
		player.Update(deltaTime, enemy, mousePosition);
		
		//-----UPDATE-----
		
		//-----DRAW-----
		window.clear(sf::Color::Black);

		map.Draw(window);
		player.Draw(window);
		enemy.Draw(window);
		frameRate.Draw(window);

		window.display();
		//-----DRAW-----

	}

	return 0;
}
