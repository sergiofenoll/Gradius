#include "Controller.hpp"

namespace sff {
	namespace logic {
		void Controller::handle_event(sf::RenderWindow &window, sf::Event event,
									  data::PlayerShipEntity::shared player) const {
			switch (event.type) {
				case sf::Event::KeyPressed:
					set_pressed(window, event, player, true);
					break;
				case sf::Event::KeyReleased:
					set_pressed(window, event, player, false);
					break;
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		void Controller::set_pressed(sf::RenderWindow &window, sf::Event event, data::PlayerShipEntity::shared player, bool pressed) const {
			switch (event.key.code) {
				case sf::Keyboard::W:
					player->actions().up = pressed;
					break;
				case sf::Keyboard::S:
					player->actions().down = pressed;
					break;
				case sf::Keyboard::A:
					player->actions().left = pressed;
					break;
				case sf::Keyboard::D:
					player->actions().right = pressed;
					break;
				case sf::Keyboard::Space:
					player->actions().fire = pressed;
					break;
				case sf::Keyboard::Escape:
					window.close();
				default:
					break;
			}
		}
	}
}
