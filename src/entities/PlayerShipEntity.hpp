#ifndef PLAYER_SHIP_ENTITY_HPP
#define PLAYER_SHIP_ENTITY_HPP

#include <fstream>
#include <memory>
#include <list>
#include "Entity.hpp"
#include "BulletEntity.hpp"
#include "../exceptions/FileException.hpp"
#include "../utils/Stopwatch.hpp"
#include "../utils/json.hpp"

namespace sff {
	namespace data {
		/**
		 * @brief
		 */
		struct Actions {
			bool up{false};
			bool down{false};
			bool left{false};
			bool right{false};
			bool fire{false};
		};

		/**
		 * @brief
		 */
		class PlayerShipEntity : public Entity {
		public:
			using shared = std::shared_ptr<PlayerShipEntity>;
			using unique = std::unique_ptr<PlayerShipEntity>;
			using weak = std::weak_ptr<PlayerShipEntity>;

			/**
			 * @brief
			 * @param config_filename
			 */
			explicit PlayerShipEntity(std::string config_filename);

			/**
			 * @brief
			 */
			void move() override;

			/**
			 * @brief
			 * @param entities
			 */
			void fire(std::list<Entity::shared> &entities) override;

			/**
			 * @brief
			 */
			void collided() override;

			/**
			 * @brief
			 * @return
			 */
			bool is_dead() const override;

			/**
			 * @brief
			 * @return
			 */
			Actions &actions();
		private:
			Actions m_actions;
			unsigned int m_tick{0};
			unsigned int m_ticks_between_bullets{10};
			std::string m_bullet_config_filename{};
		};

	}
}

#endif
