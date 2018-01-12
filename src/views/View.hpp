#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <SFML/Graphics.hpp>
#include "../models/Model.hpp"
#include "../utils/Transformation.hpp"

namespace sff
{
namespace gfx
{
/**
 * @brief
 */
class View
{
public:
	using shared = std::shared_ptr<View>;
	using unique = std::unique_ptr<View>;
	using weak = std::weak_ptr<View>;
	/**
	 * @brief
	 * @param texture_filename
	 */
	explicit View(std::string texture_filename);
	/**
	 * @brief
	 * @param texture
	 */
	explicit View(sf::Texture texture);
	/**
	 * @brief
	 * @param model
	 * @param window
	 */
	void display(data::Model& model, sf::RenderWindow& window, bool debug);
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

}
}

#endif
