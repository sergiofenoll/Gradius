#include "Game.hpp"

namespace sff
{

Game::Game()
{
	if (!m_font.loadFromFile("resources/fonts/VT323.ttf"))
	{}// Handle error
	
	
	m_menu.push_back(sf::Text("PLAY", m_font, 24));
	m_menu.push_back(sf::Text("OPTIONS", m_font, 24));
	m_menu.push_back(sf::Text("EXIT", m_font, 24));
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
					text.setString(text.getString() + "\nkey pressed");
					break;
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		window.clear();
		window.draw(text);
		window.display();
	}
}

}
