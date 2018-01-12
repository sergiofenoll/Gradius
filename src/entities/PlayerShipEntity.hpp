#ifndef PLAYER_SHIP_ENTITY_HPP
#define PLAYER_SHIP_ENTITY_HPP

#include <fstream>
#include <memory>
#include "Entity.hpp"
#include "BulletEntity.hpp"
#include "../utils/Stopwatch.hpp"
#include "../utils/json.hpp"

namespace sff
{
namespace data
{
struct Directions
{
	bool up {false};
	bool down {false};
	bool left {false};
	bool right {false};
};
/**
 * @brief
 */
class PlayerShipEntity : public Entity
{
public:
	using shared = std::shared_ptr<PlayerShipEntity>;
	using unique = std::unique_ptr<PlayerShipEntity>;
	using weak = std::weak_ptr<PlayerShipEntity>;
	/**
	 * @brief
	 */
	explicit PlayerShipEntity(std::string config_filename);
	/**
	 * @brief
	 */
	void move() override;
	/**
	 *
	 */
	void fire(std::vector<Entity::shared>& entities) override;
	/**
	 *
	 * @return
	 */
	bool is_dead() const override { return m_health <= 0; };
	/**
	 *
	 * @return
	 */
	Directions& dirs() { return m_direction; };
private:
	Directions m_direction;
};

}
}

#endif
