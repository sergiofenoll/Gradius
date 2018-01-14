#ifndef ENEMY_SHIP_ENTITY_HPP
#define ENEMY_SHIP_ENTITY_HPP

#include <fstream>
#include <memory>
#include <random>
#include <string>
#include "Entity.hpp"
#include "../controllers/Controller.hpp"
#include "../exceptions/BaseException.hpp"
#include "../utils/Stopwatch.hpp"
#include "../utils/Transformation.hpp"
#include "../utils/json.hpp"

namespace sff {
	namespace data {
		/**
		 * @brief Entity that represents the deadly enemy spaceships
		 */
		class EnemyShipEntity : public Entity {
		public:
			/**
			 * @brief Constructs a new EnemyShipEntity
			 * @param config_filename config_filename The name (and path) of the config file for the BulletEntity
			 */
			explicit EnemyShipEntity(std::string config_filename);

			/**
			 * @brief Creates a non-friendly BulletEntity and adds it to bullets
			 * Because the bullet is non-friendly it flies to the left
			 * @param bullets A list of Entities which contains the fired bullets
			 */
			void fire(std::list<Entity::shared> &bullets) override;

		private:
			bool m_fires{false};
			unsigned int m_tick{0};
			unsigned int m_ticks_between_bullets{60};
			std::string m_bullet_config_filename{};
		};
	}
}

#endif
