#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <cmath>
#include <iterator>
#include <list>
#include <memory>
#include "../models/PlayerShipEntity.hpp"

/**
 * @brief Namespace for Sergio Fenoll (Freire)
 * Extra (unique) layer, if a logic::Controller where to be included there'd be no namespace collision
 */
namespace sff {
	/**
	 * @brief Namespace for event handling
	 */
	namespace events {

		/**
		 * @brief Handles events for the player
		 */
		class Controller {
		public:
			using shared = std::shared_ptr<Controller>;
			using unique = std::unique_ptr<Controller>;
			using weak = std::weak_ptr<Controller>;

			/**
			 * @brief Handle events for the player
			 * @param window The game window. Can be closed if Escape is pressed
			 * @param event The Event to be handled
			 * @param player The player entity that will be affected by the event
			 */
			void handle_event(sf::RenderWindow &window, sf::Event event, game::PlayerShipEntity::shared player) const;

		private:
			/**
			 * @brief Turns actions for player on and off
			 * @param event The event that determines what actions must be turned on/off
			 * @param player The player whose actions will be affected
			 * @param pressed True to turn on the actions, false to turn off
			 */
			void set_pressed(sf::RenderWindow &window, sf::Event event, game::PlayerShipEntity::shared player,
							 bool pressed) const;
		};

	}
}

#endif
