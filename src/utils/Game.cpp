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
		m_levels.emplace_back(level_config_filename);
	file.close();
}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gradius");

	auto controller = std::make_shared<logic::Controller>();
	std::string player_config = m_config["player_config"];
	auto player = std::make_shared<data::PlayerShipEntity>(player_config);
	std::vector<data::Entity::shared> entities;

	while (window.isOpen())
	{
		Stopwatch::get_instance().start();
		sf::Event event {};
		while (window.pollEvent(event))
		{
			controller->handle_event(event, window, player, entities);
		}
		if (!entities.size())
		{
			std::cout << "New wave incoming, cowabunga!\n";
			entities = m_levels[m_level_nr].get_next_wave();
			// if (entities == NULL) entities = m_levels[++m_level_nr].get_next_wave();
		}

		window.clear();

		m_levels[m_level_nr].draw_background(window);
		std::vector<data::Entity::shared> survivors;
		for (auto& entity : entities) entity->move();
		controller->collision_detection(entities);
		for (auto& entity : entities) if (!entity->is_dead()) survivors.push_back(entity);
		entities = survivors;
		for (auto& entity : entities) entity->notify(window);
		player->notify(window);

		Stopwatch::get_instance().end();
		window.display();
	}
}

}

}
