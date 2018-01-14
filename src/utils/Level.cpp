#include "Level.hpp"

namespace sff {
	namespace utils {

		Level::Level(std::string config_filename) : m_background_texture(std::make_unique<sf::Texture>()) {
			std::ifstream file(config_filename);
			if (!file.is_open()) throw error::FileOpenException(config_filename);

			nlohmann::json config;
			try {
				file >> config;
			} catch (std::exception &e) {
				throw error::ParserOpenException(config_filename);
			}

			std::string background_texture_filename;
			try {
				try {
					background_texture_filename = config["background"];
				} catch (...) {
					throw error::ParserFieldException(config_filename, "background");
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			try {
				if (!m_background_texture->loadFromFile(background_texture_filename))
					throw error::FileOpenException(background_texture_filename);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			m_background_sprite.setTexture(*m_background_texture);

			try {
				try {
					m_border_config_filename = config["border_config_file"];
				} catch (...) {
					throw error::ParserFieldException(config_filename, "border_config_file");
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			for (auto wave : config["waves"]) {
				Wave w{};
				try {
					for (auto enemy : wave["enemies"]) {
						unsigned int amount;
						std::string enemy_config;

						try {
							amount = enemy["amount"];
						} catch (...) {
							throw error::ParserFieldException(config_filename, "amount");
						}

						try {
							enemy_config = enemy["enemy_config_file"];
						} catch (...) {
							throw error::ParserFieldException(config_filename, "enemy_config_file");
						}

						EnemyConfig en_conf{amount, enemy_config};
						w.enemies.push_back(en_conf);
					}
				} catch (std::exception &e) {
					std::cout << e.what() << std::endl;
				}
				try {
					for (auto obstacle : wave["obstacles"]) {
						unsigned int amount;
						std::string obstacle_config;

						try {
							amount = obstacle["amount"];
						} catch (...) {
							throw error::ParserFieldException(config_filename, "amount");
						}

						try {
							obstacle_config = obstacle["obstacle_config_file"];
						} catch (...) {
							throw error::ParserFieldException(config_filename, "obstacle_config_file");
						}

						ObstacleConfig ob_conf{amount, obstacle_config};
						w.obstacles.push_back(ob_conf);
					}
				} catch (std::exception &e) {
					std::cout << e.what() << std::endl;
				}
				m_waves.push_back(w);
			}
		}

		std::list<data::Entity::shared> Level::get_next_wave() {
			if (m_wave_nr >= m_waves.size()) return std::list<data::Entity::shared> {};
			std::list<data::Entity::shared> current_wave;
			try {
				for (EnemyConfig enemy_config : m_waves[m_wave_nr].enemies) {
					for (unsigned int _ = 0; _ < enemy_config.amount; ++_)
						current_wave.push_back(std::make_shared<data::EnemyShipEntity>(enemy_config.config_filename));
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			try {
				for (ObstacleConfig obstacle_config : m_waves[m_wave_nr].obstacles) {
					for (unsigned int _ = 0; _ < obstacle_config.amount; ++_)
						current_wave.push_back(std::make_shared<data::ObstacleEntity>(obstacle_config.config_filename));
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			++m_wave_nr;
			return current_wave;
		}

		std::list<data::Entity::shared> Level::get_borders() {
			std::list<data::Entity::shared> borders;
			try {
				borders.push_back(std::make_shared<data::BorderEntity>(m_border_config_filename, false));
				borders.push_back(std::make_shared<data::BorderEntity>(m_border_config_filename, true));
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			return borders;
		}

		void Level::draw_background(sf::RenderWindow &window) {
			window.draw(m_background_sprite);
		}

		unsigned int Level::get_wave_nr() const {
			return m_wave_nr;
		}

	}
}
