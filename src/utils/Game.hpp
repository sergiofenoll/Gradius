#pragma once

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
#include "../exceptions/BaseException.hpp"
#include "../entities/Entity.hpp"
#include "../entities/PlayerShipEntity.hpp"
#include "../entities/BulletEntity.hpp"
#include "../entities/EnemyShipEntity.hpp"
#include "../entities/ObstacleEntity.hpp"

namespace sff {
	/**
	 * @brief Namespace for different utility classes
	 */
	namespace utils {

		/**
		 * @brief Game class
		 * Encapsulates the main game loop, collision detection and UI related functions
		 * Is a Singleton because at any time only one Game should exist
		 */
		class Game : public Singleton<Game> {
			friend class Singleton<Game>;

		public:
			/**
			 * @brief The game loop
			 * Event handling, collision detection and everything inbetween happens inside here
			 */
			void run();

		private:
			explicit Game(std::string config_filename = "resources/config.json");

			/**
			 * @brief Detects collision between two lists of entities
			 * Iterates over both lists and checks if a give pair of entities collide
			 * @param e1 The first list of entities
			 * @param e2 The second list of entities
			 */
			void collision_detection(std::list<data::Entity::shared> &e1, std::list<data::Entity::shared> &e2) const;

			/**
			 * @brief Detects collision between a list of entities and a single entity
			 * Iterates over the list and checks if any member collides with the single entity
			 * This is useful for collision detection between player and everything else,
			 * because there's only one player, otherwise the player would have to be placed inside a list
			 * (to be able to call collision_detection(list, list))
			 * @param e1 The list of entities
			 * @param e2 The single entity
			 */
			void collision_detection(std::list<data::Entity::shared> &e1, data::Entity::shared e2) const;

			/**
			 * @brief Removes dead entities from a list and calls move(), fire() and notify()
			 * (in that order) on every member of the list
			 * @param window Window that will be used to notify the views
			 * @param entities The list of entities
			 * @param bullets The list of bullets new bullets will be appended to
			 */
			void update_entities(sf::RenderWindow &window, std::list<data::Entity::shared> &entities,
								 std::list<data::Entity::shared> &bullets);

			/**
			 * @brief Removes dead entities from a list and calls move() and notify()
			 * (in that order) on every member of the list
			 * @param window Window that will be used to notify the views
			 * @param entities The list of entities
			 */
			void update_entities(sf::RenderWindow &window, std::list<data::Entity::shared> &entities);

			/**
			 * @brief Draws the UI (lives, level, wave)
			 * @param window The window the UI will be drawn on
			 * @param lives The amount of lives the player has
			 */
			void draw_ui(sf::RenderWindow &window, const int &lives);

			/**
			 * @brief Draws a death screen for when the player has 0 lives left
			 * @param window The window the death screen will be drawn on
			 */
			void draw_death_screen(sf::RenderWindow &window);

			/**
			 * @brief Draws a victory screen for when the player has beat all the levels
			 * @param window The window the victory screen will be drawn on
			 */
			void draw_victory_screen(sf::RenderWindow &window);

			std::vector<Level> m_levels;
			unsigned int m_level_nr{0};
			unsigned int m_score{0};

			sf::Font m_font;
			std::string m_config_filename;
			nlohmann::json m_config;
		};

	}

}
