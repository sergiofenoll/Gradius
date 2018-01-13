#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <SFML/Graphics.hpp>
#include "../exceptions/FileException.hpp"
#include "../models/Model.hpp"
#include "../utils/Transformation.hpp"

namespace sff {
	namespace gfx {
/**
 * @brief
 */
		class View {
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
			 * @param model
			 * @param window
			 */
			void display(data::Model &model, sf::RenderWindow &window, bool hit, bool debug = false);

			/**
			 *
			 */
			float get_texture_x() const;

			/**
			 *
			 */
			float get_texture_y() const;

			/**
			 *
			 * @return
			 */
			float get_texture_radius() const;

		private:
			sf::Sprite m_sprite;
			sf::Texture m_texture;
		};

	}
}

#endif
