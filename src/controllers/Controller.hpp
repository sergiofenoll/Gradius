#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <cmath>
#include <iterator>
#include <list>
#include <memory>
#include "../entities/Entity.hpp"
#include "../entities/PlayerShipEntity.hpp"
#include "../entities/BorderEntity.hpp"

namespace sff {
	namespace logic {

		/**
		 * @brief
		 */
		class Controller {
		public:
			using shared = std::shared_ptr<Controller>;
			using unique = std::unique_ptr<Controller>;
			using weak = std::weak_ptr<Controller>;

			Controller() = default;

			/**
			 * @brief
			 * @param event
			 * @param window
			 * @param player
			 */
			void handle_event(sf::RenderWindow &window, sf::Event event, data::PlayerShipEntity::shared player) const;

			/**
			 * @brief
			 * @param e1
			 * @param e2
			 */
			void collision_detection(std::list<data::Entity::shared> &e1, std::list<data::Entity::shared> &e2) const;

			/**
			 * @brief
			 * @param e1
			 * @param e2
			 */
			void collision_detection(std::list<data::Entity::shared> &e1, data::Entity::shared e2) const;

		private:
			/**
			 * @brief
			 * @param e1
			 * @param e2
			 * @return
			 */
			bool intersects(data::Entity::shared e1, data::Entity::shared e2) const;

			/**
			 * @brief
			 * @param b
			 * @param p
			 * @return
			 */
			bool intersects(data::BorderEntity::shared b, data::PlayerShipEntity::shared p) const;

			/**
			 * @brief
			 * @param window
			 * @param event
			 * @param player
			 * @param pressed
			 */
			void set_pressed(sf::RenderWindow &window, sf::Event event, data::PlayerShipEntity::shared player,
							 bool pressed) const;
		};

	}
}

#endif
