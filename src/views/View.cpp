#include "View.hpp"

namespace sff
{
namespace gfx
{

View::View(std::string texture_filename)
{
	if (!m_texture.loadFromFile(texture_filename))
	{
		// Exception here
		std::cout << "Could not load texture from " << texture_filename << std::endl;
	}
	m_sprite.setTexture(m_texture);
	auto texture_size = m_texture.getSize();
	m_sprite.setOrigin(texture_size.x / 2, texture_size.y / 2);
}

View::View(sf::Texture texture)
{
	m_sprite.setTexture(texture);
}

void View::display(data::Model& model, sf::RenderWindow& window, bool debug)
{
	auto pos = utils::Transformation::get_instance().transform(
			window, utils::CoordPosition(model.get_x_pos(), model.get_y_pos()));
	m_sprite.setPosition(pos.x, pos.y);
	window.draw(m_sprite);
	if (debug)
	{
		auto texture_size = m_texture.getSize();
		float radius = std::max(texture_size.x, texture_size.y) / 2;
		sf::CircleShape debug_hitbox(radius);
		debug_hitbox.setOrigin(m_sprite.getOrigin());
		debug_hitbox.setPosition(m_sprite.getPosition());
		debug_hitbox.setFillColor(sf::Color::Transparent);
		debug_hitbox.setOutlineThickness(1);
		debug_hitbox.setOutlineColor(sf::Color(255, 255, 255));
		window.draw(debug_hitbox);
	}
}

}
}
