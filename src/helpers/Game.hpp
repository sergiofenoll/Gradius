#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace sff
{

/**
 */
class Game
{
public: 
	/**
	 */
	Game();
	/**
	 */
	void run();
private:
	sf::Font m_font;
	std::vector<sf::Text> m_menu;
	unsigned int m_menu_idx;
};
}

#endif
