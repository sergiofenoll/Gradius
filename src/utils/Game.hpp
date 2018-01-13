#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "json.hpp"
#include "Level.hpp"
#include "Singleton.hpp"
#include "Stopwatch.hpp"
#include "../exceptions/FileException.hpp"
#include "../entities/Entity.hpp"
#include "../entities/PlayerShipEntity.hpp"
#include "../entities/BulletEntity.hpp"
#include "../entities/EnemyShipEntity.hpp"
#include "../entities/ObstacleEntity.hpp"

namespace sff {

	namespace utils {

		/**
		 */
		class Game : public Singleton<Game> {
			friend class Singleton<Game>;

		public:
			/**
			 */
			void run();

		private:
			explicit Game(std::string config_filename = "resources/config.json");

			void update_entities(sf::RenderWindow& window, std::list<data::Entity::shared>& entities, std::list<data::Entity::shared>& bullets);

			void update_entities(sf::RenderWindow& window, std::list<data::Entity::shared>& entities);

			void draw_ui(sf::RenderWindow &window, const int &lives);

			void draw_death_screen(sf::RenderWindow& window);

			void draw_game_over_screen(sf::RenderWindow& window);

			std::vector<Level> m_levels;
			unsigned int m_level_nr{0};
			unsigned int m_score{0};

			sf::Font m_font;
			std::string m_config_filename;
			nlohmann::json m_config;
		};

	}

}

#endif
