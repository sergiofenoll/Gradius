#ifndef ENEMY_SHIP_ENTITY_HPP
#define ENEMY_SHIP_ENTITY_HPP

#include <fstream>
#include <memory>
#include <random>
#include <string>
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
class EnemyShipEntity : public Entity
{
public:
	/**
	 * @brief
	 */
	EnemyShipEntity(std::string config_filename);
private:
	bool m_fires;
	unsigned int m_tick {0};
	unsigned int m_ticks_between_bullets;
};
}
}

#endif
