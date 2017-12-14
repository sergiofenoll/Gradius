#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Singleton.hpp"

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
	Game();
	sf::Font m_font;
};

}

}

#endif
