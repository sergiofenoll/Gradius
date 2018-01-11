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
}

void View::display(data::Model& model, sf::RenderWindow& window)
{
	utils::PixelPosition pos = utils::Transformation::get_instance().transform(
			window, utils::CoordPosition(model.get_x_pos(), model.get_y_pos()));
	m_sprite.setPosition(pos.x, pos.y);
	window.draw(m_sprite);
}

}
}
