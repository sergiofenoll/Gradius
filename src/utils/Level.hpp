#pragma once

#include <fstream>
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include "json.hpp"
#include "../models/BorderEntity.hpp"
#include "../models/EnemyShipEntity.hpp"
#include "../models/ObstacleEntity.hpp"
#include "../exceptions/BaseException.hpp"

namespace sff {
	namespace utils {

		/**
		 * @brief POD struct
		 * Holds data about obstacles
		 */
		struct ObstacleConfig {
			unsigned int amount;
			std::string config_filename;
		};

		/**
		 * @brief POD struct
		 * Holds data about enemies
		 */
		struct EnemyConfig {
			unsigned int amount;
			std::string config_filename;
		};

		/**
		 * @brief POD struct
		 * Holds data about a wave
		 */
		struct Wave {
			std::vector<EnemyConfig> enemies;
			std::vector<ObstacleConfig> obstacles;
		};

		/**
		 * @brief Level class
		 * Holds level related info like waves, background and borders
		 */
		class Level {
		public:
			/**
			 * @brief Constructs a new Level
			 * @param config_filename The name (and path) of the config file for the Level
			 */
			explicit Level(std::string config_filename);

			/**
			 * @brief Returns a list of enemies and obstacles in the next wave
			 * Can return an empty list, this happens if there is no next wave
			 * @return List of entities
			 */
			std::list<game::Entity::shared> get_next_wave();

			/**
			 * @brief Returns a list of the level borders
			 * @return A list of entities
			 */
			std::list<game::Entity::shared> get_borders();

			/**
			 * @brief Draws the background
			 * @param window The window the background will be drawn on
			 */
			void draw_background(sf::RenderWindow &window);

			/**
			 * @brief Returns the current wave number
			 * Used by draw_ui() to display the wave number
			 * @return The wave number
			 */
			unsigned int get_wave_nr() const;

		private:
			std::unique_ptr<sf::Texture> m_background_texture;
			sf::Sprite m_background_sprite;
			std::vector<Wave> m_waves;
			std::string m_border_config_filename;
			unsigned int m_wave_nr{0};
		};
	}
}
