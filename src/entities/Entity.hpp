#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cmath>
#include <fstream>
#include <iostream>
#include <memory>
#include <list>
#include "../models/Model.hpp"
#include "../views/View.hpp"
#include "../utils/json.hpp"
#include "../utils/Stopwatch.hpp"

namespace sff {
	/**
	 * @brief Namespace for game data
	 */
	namespace data {
		/**
		 * @brief The base Entity class
		 * Encapsulates the Model and the View
		 */
		class Entity {
		public:
			using shared = std::shared_ptr<Entity>;
			using unique = std::unique_ptr<Entity>;
			using weak = std::weak_ptr<Entity>;

			/**
			 * @brief Constructs a new Entity
			 * Will throw an exception if the config file can't be opened
			 * If any of the required fields aren't found in the config file, a default value is used
			 * @param config_filename The name (and path) of the config file for the Entity
			 */
			explicit Entity(std::string config_filename);

			/**
			 * @brief Notifies the view to display the model
			 * @param window The window where the view will display the model
			 */
			void notify(sf::RenderWindow &window);

			/**
			 * @brief Moves the model to the left
			 * It moves to the left unless overridden
			 */
			virtual void move();

			/**
			 * @brief No-op
			 * Most Entities don't fire thus the base function does nothing
			 * @param bullets Container that will not be touched
			 */
			virtual void fire(std::list<Entity::shared> &bullets);

			/**
			 * @brief Checks the collision between this and other
			 * Collision is detected between two circles using following algorithm
			 * https://stackoverflow.com/a/1736741/7258143
			 * @param other The other entity that will be used to check collision
			 * @return True if both entities collide, false otherwise
			 */
			virtual bool collides(const Entity::shared other) const;

			/**
			 * @brief Turns on internal variable to display the Entity at half transparency for 60 ticks
			 * fade() is called whenever the entity collides with another entity;
			 */
			virtual void fade();

			/**
			 * @brief Checks if the entity is dead
			 * @return True if health < 0 or entity is outside the game window, false otherwise
			 */
			virtual bool is_dead() const;

			/**
			 * @brief Returns the model of the entity
			 * @return The model of the entity
			 */
			Model get_model() const;

			/**
			 * @brief Returns the health of the entity
			 * @return The health of the entity
			 */
			int get_health() const;

			/**
			 * @brief Returns the damage done by the entity when collision happens
			 * @return The damage done by the entity
			 */
			int get_damage() const;

			/**
			 * @brief Sets the health of the entity
			 * @param health The new health of the entity
			 */
			void set_health(const int &health);

		protected:
			Model::unique m_model;
			std::vector<gfx::View::shared> m_views;
			float m_delta_x{0};
			float m_delta_y{0};

			int m_fade_tick{0};
			bool m_fade{false};

			bool m_debug{false};
		};

	}
}

#endif
