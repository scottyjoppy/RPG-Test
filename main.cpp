#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"

int main()
{
	//-----INITIALIZE-----
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
	//-----INITIALIZE-----
	
	Player player;
	player.Initialize();
	player.Load();

	Enemy enemy;
	enemy.Initialize();
	enemy.Load();	

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

		enemy.Update();
		player.Update(enemy);
		
		//-----UPDATE-----
		
		//-----DRAW-----
		window.clear(sf::Color::Black);

		player.Draw(window);
		enemy.Draw(window);

		window.display();
		//-----DRAW-----
	}

	return 0;
}
