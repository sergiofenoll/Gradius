#include "EnemyShipEntity.hpp"

namespace sff
{
namespace data
{

EnemyShipEntity::EnemyShipEntity(std::string config_filename) :
Entity()
{
	std::ifstream file(config_filename);
	nlohmann::json config;
	file >> config;

	m_delta_x = (float) config["speed"] / utils::Stopwatch::get_instance().get_fps();
	m_delta_y = 0;

	m_health = config["max_health"];

	m_fires = config["fires"];
	if (m_fires)
	{
		m_bullet_damage = config["bullet_damage"];
		m_ticks_between_bullets = config["ticks_between_bullets"];
	}

	std::string enemy_texture = config["enemy_texture"];
	m_views.push_back(std::make_shared<gfx::View>(enemy_texture));

	std::random_device r; // Setup random seed
	std::mt19937 mt(r()); // Create a PRNG eninge (using the Mersenne twister algorithm)

	std::uniform_real_distribution<float> x_dist(4.5, 6.0);
	m_model->set_x_pos(x_dist(mt));

	std::uniform_real_distribution<float> y_dist(0.5, 2.5);
	m_model->set_y_pos(y_dist(mt));

	// std::cout << m_views[0]->get_max_texture_size() / 2 << std::endl;
	auto game_coords = utils::Transformation::get_instance().transform(
			utils::PixelPosition(m_views[0]->get_max_texture_size() / 2, 0));
	m_model->set_radius(game_coords.x);

	file.close();
}

}
}
