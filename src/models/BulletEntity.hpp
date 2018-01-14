#ifndef BULLET_ENTITY_HPP
#define BULLET_ENTITY_HPP

#include <memory>
#include <string>
#include "Entity.hpp"
#include "../utils/Stopwatch.hpp"
#include "../exceptions/BaseException.hpp"

namespace sff {
	namespace game {
		/**
		 * @brief Entity that represents the deadly projectiles fired by the spaceships
		 */
		class BulletEntity : public Entity {
		public:
			/**
			 * @brief Constructs a new BulletEntity
			 * @param config_filename The name (and path) of the config file for the BulletEntity
			 * @param pos_x X coordinate (game coordinates) of bullet spawn
			 * @param pos_y Y coordinate (game coordinates) of bullet spawn
			 */
			BulletEntity(std::string config_filename, float pos_x, float pos_y);

			/**
			 * @brief Moves the bullet to the left or the right
			 * If the bullet is friendly (fired by the player) it moves to the right
			 * If the bullet isn't friendly (fired by an enemy ship) it moves to the left
			 * While inheritance could have been used here,
			 * it seemed a bit overly complicated when a bool sufficed
			 */
			void move() override;

			/**
			 * @brief No-op
			 * Bullets shouldn't fade when colliding
			 */
			void fade() override;

			/**
			 * @brief Checks if the bullet is dead by looking at its health and position
			 * @return True if health < 0 or the bullet is outside the game window, false otherwise
			 */
			bool is_dead() const override;

		private:
			bool m_friendly{true};
		};

	}
}

#endif
