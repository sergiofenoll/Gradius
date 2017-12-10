#include "Game.hpp"

namespace sff
{

namespace utils
{

Game::Game()
{
	if (!m_font.loadFromFile("resources/fonts/VT323.ttf"))
	{}// Handle error
}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gradius");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::KeyPressed:
					break;
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		window.clear();
		window.display();
	}
}

}

}
