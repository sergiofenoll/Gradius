#include "View.hpp"

namespace sff {
	namespace gfx {

		View::View(std::string texture_filename) {
			if (!m_texture.loadFromFile(texture_filename)) throw error::FileOpenException(texture_filename);
			m_sprite.setTexture(m_texture);
			auto texture_size = m_texture.getSize();
			m_sprite.setOrigin(texture_size.x / 2, texture_size.y / 2);
		}

		void View::display(sf::RenderWindow &window, data::Model &model, bool fade, bool debug) {
			if (model.get_x_pos() > (4 + get_texture_width()) or model.get_x_pos() < (0 - get_texture_width()))
				return; // No need to draw entities outside the game window

			auto pos = utils::Transformation::get_instance().transform(
					utils::CoordPosition(model.get_x_pos(), model.get_y_pos()));

			m_sprite.setPosition(pos.x, pos.y);
			m_sprite.setColor(sf::Color(255, 255, 255, (fade ? 128 : 255)));
			window.draw(m_sprite);

			if (debug) {
				auto texture_size = m_texture.getSize();
				float radius = std::min(texture_size.x, texture_size.y) / 2;

				sf::CircleShape debug_hitbox(radius);

				debug_hitbox.setOrigin(m_sprite.getOrigin());
				debug_hitbox.setPosition(m_sprite.getPosition());

				debug_hitbox.setFillColor(sf::Color::Transparent);
				debug_hitbox.setOutlineThickness(1);
				debug_hitbox.setOutlineColor(sf::Color(255, 255, 255));

				window.draw(debug_hitbox);
			}
		}

		float View::get_texture_width() const {
			return utils::Transformation::get_instance().transform_x((unsigned int) m_texture.getSize().x);
		}

		float View::get_texture_height() const {
			return utils::Transformation::get_instance().transform_y((unsigned int) m_texture.getSize().y);
		}

		float View::get_texture_radius() const {
			auto x_size = get_texture_width() / 2;
			auto y_size = get_texture_height() / 2;
			return std::min(x_size, y_size);
		}

	}
}
