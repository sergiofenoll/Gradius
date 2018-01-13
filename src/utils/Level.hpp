#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <fstream>
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include "json.hpp"
#include "../entities/BorderEntity.hpp"
#include "../entities/EnemyShipEntity.hpp"
#include "../entities/ObstacleEntity.hpp"
#include "../exceptions/FileException.hpp"

namespace sff {
	namespace utils {

		struct ObstacleConfig {
			unsigned int amount;
			std::string config_filename;
		};

		struct EnemyConfig {
			unsigned int amount;
			std::string config_filename;
		};

		struct Wave {
			std::vector<EnemyConfig> enemies;
			std::vector<ObstacleConfig> obstacles;
		};

		/**
		 * @brief
		 */
		class Level {
		public:
			/**
			 * @brief
			 * @param config_filename
			 */
			explicit Level(std::string config_filename);

			/**
			 * @brief
			 * @return
			 */
			std::list<data::Entity::shared> get_next_wave();

			/**
			 * @brief
			 * @return
			 */
			std::list<data::Entity::shared> get_borders();

			/**
			 * @brief
			 * @param window
			 */
			void draw_background(sf::RenderWindow &window);

			/**
			 * @brief
			 * @return
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

#endif