#ifndef GAME_HPP
#define GAME_HPP

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "json.hpp"
#include "Level.hpp"
#include "Singleton.hpp"
#include "Stopwatch.hpp"
#include "../entities/Entity.hpp"
#include "../entities/PlayerShipEntity.hpp"
#include "../entities/BulletEntity.hpp"
#include "../entities/EnemyShipEntity.hpp"
#include "../entities/ObstacleEntity.hpp"

namespace sff
{

namespace utils
{

/**
 */
class Game : public Singleton<Game>
{
friend class Singleton<Game>;
public:
	/**
	 */
	void run();
private:
	/**
	 */
	explicit Game(std::string config_filename = "resources/config.json");
	std::vector<Level> m_levels;
	unsigned int m_level_nr {0};
	nlohmann::json m_config;
};

}

}

#endif
