#ifndef ENEMY_SHIP_ENTITY_HPP
#define ENEMY_SHIP_ENTITY_HPP

#include <fstream>
#include <memory>
#include <random>
#include <string>
#include "Entity.hpp"
#include "../controllers/Controller.hpp"
#include "../exceptions/FileException.hpp"
#include "../utils/Stopwatch.hpp"
#include "../utils/Transformation.hpp"
#include "../utils/json.hpp"

namespace sff {
	namespace data {
/**
 * @brief
 */
		class EnemyShipEntity : public Entity {
		public:
			/**
			 * @brief
			 */
			explicit EnemyShipEntity(std::string config_filename);

			/**
			 * @brief
			 * @param entities
			 */
			void fire(std::list<Entity::shared> &entities) override;

			/**
			 * @brief
			 */
			void collided() override;

		private:
			bool m_fires {false};
			unsigned int m_tick{0};
			unsigned int m_ticks_between_bullets{60};
			std::string m_bullet_config_filename{};
		};
	}
}

#endif
