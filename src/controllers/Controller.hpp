#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <cmath>
#include <memory>
#include "../entities/Entity.hpp"

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
	void handle_event(sf::Event event, sf::RenderWindow& window, data::Entity::shared player, std::vector<data::Entity::shared>& entities)
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
						player->move(data::Directions {true});
						break;
					case sf::Keyboard::S:
						player->move(data::Directions {false, true});
						break;
					case sf::Keyboard::A:
						player->move(data::Directions {false, false, true});
						break;
					case sf::Keyboard::D:
						player->move(data::Directions {false, false, false, true});
						break;
					case sf::Keyboard::Space:
						player->fire(entities);
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
	 */
	bool collide(const data::Model& m1, const data::Model& m2 )
	{
		return std::pow(m2.get_x_pos() - m1.get_x_pos(), 2)
			   + std::pow(m1.get_y_pos() - m2.get_y_pos(), 2)
			   <= std::pow(m1.get_radius() + m2.get_radius(), 2);
	};
};

}
}

#endif
