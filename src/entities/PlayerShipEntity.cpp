#include "PlayerShipEntity.hpp"
#include "BulletEntity.hpp"

namespace sff
{
namespace data
{

PlayerShipEntity::PlayerShipEntity(std::string config_filename) :
Entity()
{
	std::ifstream file(config_filename);
	nlohmann::json config;
	file >> config;

	std::string player_texture = config["player_texture"];
	m_views.push_back(std::make_shared<gfx::View>(player_texture));
	m_delta_x = (float) config["speed"] / utils::Stopwatch::get_instance().get_fps();
	m_delta_y = (float) config["speed"] / utils::Stopwatch::get_instance().get_fps();

	std::string bullet_texture = config["bullet_texture"];
	m_bullet_texture = bullet_texture;
	m_bullet_damage = config["bullet_damage"];
	m_bullet_speed = config["bullet_speed"];

	file.close();
}

void PlayerShipEntity::move(Directions directions)
{
	if (directions.up) m_model->change_pos(0, -m_delta_y);
	if (directions.down) m_model->change_pos(0, m_delta_y);
	if (directions.left) m_model->change_pos(-m_delta_x, 0);
	if (directions.right) m_model->change_pos(m_delta_x, 0);
}

void PlayerShipEntity::fire(std::vector<Entity::shared>& entities)
{
	double x = m_model->get_x_pos();
	double y = m_model->get_y_pos();
	return entities.push_back(std::make_shared<BulletEntity>(m_bullet_texture, m_bullet_speed, m_bullet_damage, x, y, true));
}

}
}
