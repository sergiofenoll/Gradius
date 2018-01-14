#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../utils/json.hpp"
#include "../utils/Level.hpp"
#include "../utils/Singleton.hpp"
#include "../utils/Stopwatch.hpp"
#include "../exceptions/BaseException.hpp"
#include "Entity.hpp"
#include "PlayerShipEntity.hpp"
#include "BulletEntity.hpp"
#include "EnemyShipEntity.hpp"
#include "ObstacleEntity.hpp"

namespace sff {
	namespace game {

		/**
		 * @brief Game class
		 * Encapsulates the main game loop, collision detection and UI related functions
		 * Is a Singleton because at any time only one Game should exist
		 */
		class Game : public utils::Singleton<Game> {
			friend class utils::Singleton<Game>;

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
			 * @param entities1 The first list of entities
			 * @param entities2 The second list of entities
			 */
			void collision_detection(std::list<game::Entity::shared> &entities1,
									 std::list<game::Entity::shared> &entities2) const;

			/**
			 * @brief Detects collision between a list of entities and a single entity
			 * Iterates over the list and checks if any member collides with the single entity
			 * This is useful for collision detection between player and everything else,
			 * because there's only one player, otherwise the player would have to be placed inside a list
			 * (to be able to call collision_detection(list, list))
			 * @param entities The list of entities
			 * @param single_entity The single entity
			 */
			void collision_detection(std::list<game::Entity::shared> &entities,
									 game::Entity::shared single_entity) const;

			/**
			 * @brief Removes dead entities from a list and calls move(), fire() and notify()
			 * (in that order) on every member of the list
			 * @param window Window that will be used to notify the views
			 * @param entities The list of entities
			 * @param bullets The list of bullets new bullets will be appended to
			 */
			void update_entities(sf::RenderWindow &window, std::list<game::Entity::shared> &entities,
								 std::list<game::Entity::shared> &bullets);

			/**
			 * @brief Removes dead entities from a list and calls move() and notify()
			 * (in that order) on every member of the list
			 * @param window Window that will be used to notify the views
			 * @param entities The list of entities
			 */
			void update_entities(sf::RenderWindow &window, std::list<game::Entity::shared> &entities);

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

			std::vector<utils::Level> m_levels;
			unsigned int m_level_nr{0};

			sf::Font m_font;
			std::string m_config_filename;
			nlohmann::json m_config;
		};

	}

}
