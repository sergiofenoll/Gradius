#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "json.hpp"
#include "../entities/EnemyShipEntity.hpp"

namespace sff {
namespace utils {

struct EnemyConfig
{
	unsigned int amount;
	std::string config_filename;
};

struct Wave
{
	std::vector<EnemyConfig> enemies;
};
/**
 * @brief
 */
class Level
{
public:
	/**
	 * @brief
	 * @param config_filename
	 */
	explicit Level(std::string config_filename);
	std::vector<data::Entity::shared> get_next_wave();
private:
	sf::Texture m_background;
	std::vector<Wave> m_waves;
	unsigned int m_wave_nr {0};
};
}}

#endif
