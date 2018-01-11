#include "Level.hpp"

namespace sff
{
namespace utils
{

Level::Level(std::string config_filename)
{
	std::ifstream file(config_filename);
	nlohmann::json config;
	file >> config;
	try
	{
		if (!m_background.loadFromFile(config["level_background"]))
		{
			// Exception
		}
	} catch (...)
	{}
	for (auto wave : config["waves"])
	{
		Wave w {};
		for (auto enemy : wave["enemies"]) {
			EnemyConfig en_conf{enemy["amount"], enemy["enemy_config_file"]};
			w.enemies.push_back(en_conf);
		}
		m_waves.push_back(w);
	}
	file.close();
}

std::vector<data::Entity::shared> Level::get_next_wave()
{
	std::vector<data::Entity::shared> current_wave;
	for (EnemyConfig enemy_config : m_waves[m_wave_nr].enemies)
	{
		for (unsigned int _ = 0; _ < enemy_config.amount; ++_)
			current_wave.push_back(std::make_shared<data::EnemyShipEntity>(nullptr, enemy_config.config_filename));
	}
	++m_wave_nr;
	return current_wave;
}

}
}
