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

		void Controller::collision_detection(std::list<data::Entity::shared> &e1,
											 std::list<data::Entity::shared> &e2) const {
			for (auto it1 = e1.begin(); it1 != e1.end(); ++it1) {
				for (auto it2 = e2.begin(); it2 != e2.end(); ++it2) {
					if ((*it1)->intersects(*it2)) {
						int old_health1 = (*it1)->get_health();
						int old_health2 = (*it2)->get_health();
						int new_health1 = old_health1 - (*it2)->get_damage();
						int new_health2 = old_health2 - (*it1)->get_damage();
						(*it1)->set_health(new_health1);
						(*it2)->set_health(new_health2);
						(*it1)->collided();
						(*it2)->collided();
					}
				}
			}
		}

		void Controller::collision_detection(std::list<data::Entity::shared> &e1, data::Entity::shared e2) const {
			for (auto it1 = e1.begin(); it1 != e1.end(); ++it1) {
				if ((*it1)->intersects(e2)) {
					int old_health1 = (*it1)->get_health();
					int old_health2 = e2->get_health();
					int new_health1 = old_health1 - e2->get_damage();
					int new_health2 = old_health2 - (*it1)->get_damage();
					(*it1)->set_health(new_health1);
					e2->set_health(new_health2);
					(*it1)->collided();
					e2->collided();
				}
			}
		}

		void Controller::set_pressed(sf::RenderWindow &window, sf::Event event, data::PlayerShipEntity::shared player,
									 bool pressed) const {
			switch (event.key.code) {
				case sf::Keyboard::Escape:
					window.close();
					break;
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
				default:
					break;
			}
		}
	}
}
