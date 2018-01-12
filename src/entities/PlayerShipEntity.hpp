#ifndef PLAYER_SHIP_ENTITY_HPP
#define PLAYER_SHIP_ENTITY_HPP

#include <fstream>
#include <memory>
#include "Entity.hpp"
#include "../controllers/Controller.hpp"
#include "../utils/Stopwatch.hpp"
#include "../utils/json.hpp"

namespace sff
{
namespace data
{
/**
 * @brief
 */
class PlayerShipEntity : public Entity
{
public:
	/**
	 * @brief
	 */
	explicit PlayerShipEntity(std::string config_filename);
	/**
	 * @brief
	 */
	void move(Directions directions) override;
	/**
	 *
	 */
	void fire(std::vector<Entity::shared>& entities) override;
	/**
	 *
	 * @return
	 */
	bool is_dead() const override { return m_health <= 0; };

};

}
}

#endif
