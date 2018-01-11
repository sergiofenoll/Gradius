#include "Game.hpp"

namespace sff
{

namespace utils
{

Game::Game(std::string config_filename)
{
	std::ifstream file(config_filename);
	file >> m_config;
	for (std::string level_config_filename : m_config["levels"])
		m_levels.push_back(Level((level_config_filename)));
	file.close();
}

void Game::run()
{
	auto controller = std::make_shared<logic::Controller>();
	auto player = std::make_shared<data::PlayerShipEntity>(controller);
	std::vector<data::Entity::shared> entities;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Gradius");
	while (window.isOpen())
	{
		Stopwatch::get_instance().start();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::KeyPressed:
					// TODO: Move this to the controller (maybe add a class to encapsulate the SFML keyboard)
					switch (event.key.code)
					{
						case sf::Keyboard::Escape:
							window.close();
							break;
						case sf::Keyboard::W:
							player->control(data::Entity::Key::UP);
							break;
						case sf::Keyboard::A:
							player->control(data::Entity::Key::LEFT);
							break;
						case sf::Keyboard::S:
							player->control(data::Entity::Key::DOWN);
							break;
						case sf::Keyboard::D:
							player->control(data::Entity::Key::RIGHT);
							break;
						case sf::Keyboard::Space:
							player->control(data::Entity::Key::SPACE);
							break;
						default:
							continue;
					}
					break;
				case sf::Event::Closed:
					window.close();
					break;
				default:	
					break;
			}
		}
		if (!entities.size())
		{
			std::cout << "New wave incoming, cowabunga!\n";
			entities = m_levels[m_level_nr].get_next_wave();
			for (auto& entity : entities) entity->set_controller(controller);
		}
		window.clear();
		m_levels[m_level_nr].draw_background(window);
		for (auto& entity : entities)
		{
			entity->control(data::Entity::Key::NONE);
			entity->notify(window);
			player->notify(window);
		}
		Stopwatch::get_instance().end();
		window.display();
	}
}

}

}
