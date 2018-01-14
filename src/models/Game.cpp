#include "Game.hpp"

namespace sff {

	namespace game {

		Game::Game(std::string config_filename) {
			std::ifstream file(config_filename);
			if (!file.is_open()) throw error::FileOpenException(config_filename);

			try {
				file >> m_config;
			} catch (...) {
				throw error::ParserOpenException(config_filename);
			}

			std::string font_file;
			try {
				try {
					font_file = m_config["font"];
				} catch (...) {
					throw error::ParserFieldException(config_filename, "font");
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			try {
				if (!m_font.loadFromFile(font_file)) throw error::FileOpenException(font_file);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			try {
				for (std::string level_config_filename : m_config["levels"]) {
					try {
						m_levels.emplace_back(level_config_filename);
					} catch (std::exception &e) {
						std::cout << e.what() << std::endl;
					}
				}
				if (m_levels.empty())
					throw error::BaseException(config_filename,
											   "no levels declared in config file, game cannot proceed");
			} catch (error::BaseException &e) {
				throw;
			} catch (...) {
				throw error::ParserFieldException(config_filename, "levels");
			}
		}

		void Game::run() {
			sf::RenderWindow window(sf::VideoMode(800, 600), "Gradius");
			utils::Transformation::get_instance().set_resolution(800, 600);

			auto controller = std::make_shared<events::Controller>();

			std::string player_config;
			try {
				player_config = m_config["player_config_file"];
			} catch (...) {
				throw error::ParserFieldException(m_config_filename, "player_config_file");
			}

			auto player = std::make_shared<game::PlayerShipEntity>(player_config);

			std::list<game::Entity::shared> enemies;
			std::list<game::Entity::shared> borders;
			std::list<game::Entity::shared> player_bullets;
			std::list<game::Entity::shared> enemy_bullets;

			while (window.isOpen()) {
				utils::Stopwatch::get_instance().start();
				sf::Event event{};
				while (window.pollEvent(event)) {
					controller->handle_event(window, event, player);
				}

				if (!enemies.size()) {
					enemies = m_levels[m_level_nr].get_next_wave();
					if (enemies.empty()) {
						if (++m_level_nr < m_levels.size()) {
							enemies = m_levels[m_level_nr].get_next_wave();
						} else {
							draw_victory_screen(window);
							break;
						}
					}
				}
				borders = m_levels[m_level_nr].get_borders();

				window.clear();

				m_levels[m_level_nr].draw_background(window);

				collision_detection(player_bullets, enemies);
				collision_detection(enemy_bullets, player);
				collision_detection(enemies, player);
				collision_detection(borders, player);

				update_entities(window, borders);
				update_entities(window, player_bullets);
				update_entities(window, enemy_bullets);
				update_entities(window, enemies, enemy_bullets);

				player->move();
				player->fire(player_bullets);
				player->notify(window);
				if (player->is_dead()) draw_death_screen(window);

				draw_ui(window, player->get_health());

				utils::Stopwatch::get_instance().end();
				window.display();
			}
		}

		void Game::collision_detection(std::list<game::Entity::shared> &entities1,
									   std::list<game::Entity::shared> &entities2) const {
			for (auto e1 : entities1) {
				for (auto e2 : entities2) {
					if (e1->collides(e2)) {
						int old_health1 = e1->get_health();
						int old_health2 = e2->get_health();
						int new_health1 = old_health1 - e2->get_damage();
						int new_health2 = old_health2 - e1->get_damage();
						e1->set_health(new_health1);
						e2->set_health(new_health2);
						e1->fade();
						e2->fade();
					}
				}
			}
		}

		void
		Game::collision_detection(std::list<game::Entity::shared> &entities, game::Entity::shared single_entity) const {
			for (auto entity : entities) {
				if (entity->collides(single_entity)) {
					int old_health1 = entity->get_health();
					int old_health2 = single_entity->get_health();
					int new_health1 = old_health1 - single_entity->get_damage();
					int new_health2 = old_health2 - entity->get_damage();
					entity->set_health(new_health1);
					single_entity->set_health(new_health2);
					entity->fade();
					single_entity->fade();
				}
			}
		}

		void Game::update_entities(sf::RenderWindow &window, std::list<game::Entity::shared> &entities,
								   std::list<game::Entity::shared> &bullets) {
			for (auto it = entities.begin(); it != entities.end();) {
				if ((*it)->is_dead())
					it = entities.erase(it);
				else {
					(*it)->move();
					(*it)->fire(bullets);
					(*it)->notify(window);
					++it;
				}
			}
		}

		void Game::update_entities(sf::RenderWindow &window, std::list<game::Entity::shared> &entities) {
			for (auto it = entities.begin(); it != entities.end();) {
				if ((*it)->is_dead())
					it = entities.erase(it);
				else {
					(*it)->move();
					(*it)->notify(window);
					++it;
				}
			}
		}

		void Game::draw_ui(sf::RenderWindow &window, const int &lives) {
			sf::Text text;

			text.setFont(m_font);
			text.setString("Lives: " + std::to_string(lives) + " Level: " + std::to_string(m_level_nr + 1) + " Wave: " +
						   std::to_string(m_levels[m_level_nr].get_wave_nr()));
			text.setCharacterSize(24);
			text.setColor(sf::Color::Black);
			text.setStyle(sf::Text::Bold);

			window.draw(text);
		}

		void Game::draw_death_screen(sf::RenderWindow &window) {
			sf::Text game_over;
			sf::Text subtext;

			game_over.setFont(m_font);
			game_over.setString("GAME OVER");
			game_over.setCharacterSize(120);
			game_over.setOrigin(game_over.getLocalBounds().width / 2, game_over.getLocalBounds().height / 2);
			game_over.setPosition(window.getSize().x / 2,
								  (window.getSize().y / 2) - (2 * game_over.getLocalBounds().height));
			game_over.setStyle(sf::Text::Bold);
			game_over.setColor(sf::Color::Red);

			subtext.setFont(m_font);
			subtext.setString("        With your ship now destroyed,\n"
									  " the galactic quest you embarked on is over.\n"
									  "Countless enemy ships will flood Geon Prime.\n\n"
									  "              All hope is lost.\n"
									  "             (Press ESC to exit)");
			subtext.setCharacterSize(36);
			subtext.setOrigin(subtext.getLocalBounds().width / 2, subtext.getLocalBounds().height / 2);
			subtext.setPosition(window.getSize().x / 2, (window.getSize().y / 2) +
														(subtext.getLocalBounds().height / 2));
			subtext.setColor(sf::Color::Red);

			window.clear();
			window.draw(game_over);
			window.draw(subtext);
			window.display();

			sf::Event event{};
			while (true) {
				utils::Stopwatch::get_instance().start();
				window.pollEvent(event);
				if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape) {
					window.close();
					break;
				}
				utils::Stopwatch::get_instance().end();
			}
		}

		void Game::draw_victory_screen(sf::RenderWindow &window) {
			sf::Text game_over;
			sf::Text subtext;

			game_over.setFont(m_font);
			game_over.setString("GAME OVER");
			game_over.setCharacterSize(120);
			game_over.setOrigin(game_over.getLocalBounds().width / 2, game_over.getLocalBounds().height / 2);
			game_over.setPosition(window.getSize().x / 2,
								  (window.getSize().y / 2) - (2 * game_over.getLocalBounds().height));
			game_over.setStyle(sf::Text::Bold);
			game_over.setColor(sf::Color::Green);


			subtext.setFont(m_font);
			subtext.setString("     With the enemy fleet now destroyed,\n"
									  " the galactic quest you embarked on is over.\n"
									  "   You can safely return to Geon Prime.\n\n"
									  "             The galaxy is saved.\n"
									  "             (Press ESC to exit)");
			subtext.setCharacterSize(36);
			subtext.setOrigin(subtext.getLocalBounds().width / 2, subtext.getLocalBounds().height / 2);
			subtext.setPosition(window.getSize().x / 2, (window.getSize().y / 2) +
														(subtext.getLocalBounds().height / 2));
			subtext.setColor(sf::Color::Green);

			window.clear();
			window.draw(game_over);
			window.draw(subtext);
			window.display();

			sf::Event event{};
			while (true) {
				utils::Stopwatch::get_instance().start();
				window.pollEvent(event);
				if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape) {
					window.close();
					break;
				}
				utils::Stopwatch::get_instance().end();
			}
		}

	}

}
