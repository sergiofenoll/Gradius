#include "PlayerShipEntity.hpp"

namespace sff
{
namespace data
{

PlayerShipEntity::PlayerShipEntity(logic::Controller::shared controller) :
Entity(controller)
{
	m_views.push_back(std::make_shared<gfx::View>("resources/sprites/player/ship1.png"));
}

void PlayerShipEntity::control(const Key& key)
{
	switch (key)
	{
		case Key::UP:
			if (auto lock = m_controller.lock())
				lock->move(*m_model, 0.0, -0.01);
			break;
		case Key::LEFT:
			if (auto lock = m_controller.lock())
				lock->move(*m_model, -0.01, 0.0);
			break;
		case Key::DOWN:
			if (auto lock = m_controller.lock())
				lock->move(*m_model, 0.0, 0.01);
			break;
		case Key::RIGHT:
			if (auto lock = m_controller.lock())
				lock->move(*m_model, 0.01, 0.0);
			break;
		case Key::SPACE:
			if (auto lock = m_controller.lock())
				lock->fire(*m_model);
			break;
		default:
			break;
	}
}

}
}
