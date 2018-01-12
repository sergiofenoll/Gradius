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
	/**
	 * @brief
	 * @return
	 */
	std::vector<data::Entity::shared> get_next_wave();
	/**
	 * @brief
	 * @param window
	 */
	void draw_background(sf::RenderWindow& window);
private:
	sf::Texture m_background_texture;
	sf::Sprite m_background_sprite;
	std::vector<Wave> m_waves;
	unsigned int m_wave_nr {0};
};
}}

#endif