#ifndef PLAYER_SHIP_ENTITY_HPP
#define PLAYER_SHIP_ENTITY_HPP

#include <memory>
#include "Entity.hpp"

namespace sff
{
namespace data
{
/**
 */
class PlayerShipEntity : public Entity
{
public:
	/**
	 */
	explicit PlayerShipEntity(logic::Controller::shared controller);
	/**
	 */
	void control(const Key& key) override;
};

}
}

#endif
