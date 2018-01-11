#include "EnemyShipEntity.hpp"

namespace sff
{
namespace data
{
EnemyShipEntity::EnemyShipEntity(logic::Controller::shared controller, std::string config_filename) :
Entity(controller)
{
	std::ifstream file(config_filename);
	nlohmann::json config;
	file >> config;

	m_delta_x = config["delta_x"];
	m_delta_y = config["delta_y"];
	std::cout << m_delta_x << std::endl;
	m_fires = config["fires"];
	if (m_fires)
	{
		m_damage = config["damage"];
		m_ticks_between_bullets = config["ticks_between_bullets"];
	}
	m_health = config["max_health"];
	m_views.push_back(std::make_shared<gfx::View>("resources/sprites/enemy/enemy1.png"));

	m_model->set_x_pos(4.0);
	m_model->set_y_pos(1.5);
	file.close();
}

void EnemyShipEntity::control(const Key &key)
{
	if (m_model->get_x_pos() < 0) m_dead = true;
	if (m_model->get_y_pos() < 0 or m_model->get_y_pos() > 4) m_delta_y = -m_delta_y;
	if (auto lock = m_controller.lock()) {
		lock->move(*m_model, m_delta_x, m_delta_y);
		if (m_fires and m_tick++ == m_ticks_between_bullets)
		{
			lock->fire(*m_model);
			m_tick = 0;
		}

	}
}

}
}
