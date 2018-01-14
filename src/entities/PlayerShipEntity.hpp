#ifndef PLAYER_SHIP_ENTITY_HPP
#define PLAYER_SHIP_ENTITY_HPP

#include <fstream>
#include <memory>
#include <list>
#include "Entity.hpp"
#include "BulletEntity.hpp"
#include "../exceptions/BaseException.hpp"
#include "../utils/Stopwatch.hpp"
#include "../utils/json.hpp"

namespace sff {
	namespace data {
		/**
		 * @brief POD struct
		 * Holds bools denoting possible player actions
		 */
		struct Actions {
			bool up{false};
			bool down{false};
			bool left{false};
			bool right{false};
			bool fire{false};
		};

		/**
		 * @brief Entity that represents the friendly player spaceship
		 */
		class PlayerShipEntity : public Entity {
		public:
			using shared = std::shared_ptr<PlayerShipEntity>;
			using unique = std::unique_ptr<PlayerShipEntity>;
			using weak = std::weak_ptr<PlayerShipEntity>;

			/**
			 * @brief Constructs a new PlayerShipEntity
			 * @param config_filename The name (and path) of the config file for the PlayerShipEntity
			 */
			explicit PlayerShipEntity(std::string config_filename);

			/**
			 * @brief Overrides move() to use player actions and bound the player to the game window
			 */
			void move() override;

			/**
			 * @brief Creates friendly bullets and appends them to bullets
			 * Friendly bullets go to the right
			 * @param bullets The list of bullets
			 */
			void fire(std::list<Entity::shared> &bullets) override;

			/**
			 * @brief The same fade as any other entity but also respawns the player to it's original position
			 */
			void fade() override;

			/**
			 * @brief Overrides is_dead() so that it only checks health
			 * @return True if health < 0, false otherwise
			 */
			bool is_dead() const override;

			/**
			 * @brief Returns a reference to the player actions
			 * @return A reference to the player actions
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
