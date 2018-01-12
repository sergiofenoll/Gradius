#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <cmath>
#include <memory>
#include "../entities/Entity.hpp"
#include "../entities/PlayerShipEntity.hpp"

namespace sff
{
namespace logic
{

class Controller
{
public:
	using shared = std::shared_ptr<Controller>;
	using unique = std::unique_ptr<Controller>;
	using weak = std::weak_ptr<Controller>;
	/**
	 */
	Controller() = default;
	/**
	 * @brief
	 * @param event
	 */
	void handle_event(sf::Event event, sf::RenderWindow& window, data::PlayerShipEntity::shared player, std::vector<data::Entity::shared>& entities)
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						window.close();
						break;
					case sf::Keyboard::W:
						player->dirs().up = true;
						break;
					case sf::Keyboard::S:
						player->dirs().down = true;
						break;
					case sf::Keyboard::A:
						player->dirs().left = true;
						break;
					case sf::Keyboard::D:
						player->dirs().right = true;
						break;
					case sf::Keyboard::Space:
						player->fire(entities);
						break;
					default:
						break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						window.close();
						break;
					case sf::Keyboard::W:
						player->dirs().up = false;
						break;
					case sf::Keyboard::S:
						player->dirs().down = false;
						break;
					case sf::Keyboard::A:
						player->dirs().left = false;
						break;
					case sf::Keyboard::D:
						player->dirs().right = false;
						break;
					default:
						break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
		}
	}
	/**
	 *
	 * @param entities
	 */
	void collision_detection(std::vector<data::Entity::shared>& entities)
	{
		for (auto it1 = entities.begin(); it1 != entities.end(); ++it1)
		{
			for (auto it2 = it1 + 1; it2 != entities.end(); ++it2)
			{
				if (collide((*it1)->get_model_obj(), (*it2)->get_model_obj()))
				{
					int old_health1 = (*it1)->get_health();
					int old_health2 = (*it2)->get_health();
					int new_health1 = old_health1 - (*it2)->get_damage();
					int new_health2 = old_health2 - (*it1)->get_damage();
					(*it1)->set_health(new_health1);
					(*it2)->set_health(new_health2);
				}
			}
		}
	}
	/**
	 *
	 */
	bool collide(const data::Model& m1, const data::Model& m2 )
	{
		return std::pow(m2.get_x_pos() - m1.get_x_pos(), 2)
			   + std::pow(m2.get_y_pos() - m1.get_y_pos(), 2)
			   <= std::pow(m1.get_radius() + m2.get_radius(), 2);
	};
};

}
}

#endif
