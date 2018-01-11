#ifndef ENEMY_SHIP_ENTITY_HPP
#define ENEMY_SHIP_ENTITY_HPP

#include <fstream>
#include <memory>
#include <string>
#include "Entity.hpp"
#include "../controllers/Controller.hpp"
#include "../utils/json.hpp"

namespace sff
{
namespace data
{
/**
 */
class EnemyShipEntity : public Entity
{
public:
	/**
	 */
	EnemyShipEntity(logic::Controller::shared controller, std::string config_filename);
	void control(const Key& key) override;
private:
	double m_delta_x;
	double m_delta_y;
	bool m_fires;
	unsigned int m_damage;
	unsigned int m_tick {0};
	unsigned int m_ticks_between_bullets;
	int m_health;
};
}
}

#endif
