#include "Controller.hpp"

namespace sff {
	namespace events {
		void Controller::handle_event(sf::RenderWindow &window, sf::Event event,
									  game::PlayerShipEntity::shared player) const {
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

		void Controller::set_pressed(sf::RenderWindow &window, sf::Event event, game::PlayerShipEntity::shared player,
									 bool pressed) const {
			switch (event.key.code) {
				case sf::Keyboard::W:
				case sf::Keyboard::Z:
				case sf::Keyboard::Up:
					player->actions().up = pressed;
					break;
				case sf::Keyboard::S:
				case sf::Keyboard::Down:
					player->actions().down = pressed;
					break;
				case sf::Keyboard::A:
				case sf::Keyboard::Q:
				case sf::Keyboard::Left:
					player->actions().left = pressed;
					break;
				case sf::Keyboard::D:
				case sf::Keyboard::Right:
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
