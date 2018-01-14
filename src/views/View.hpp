#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <SFML/Graphics.hpp>
#include "../exceptions/BaseException.hpp"
#include "../models/ModelData.hpp"
#include "../utils/Transformation.hpp"

namespace sff {
	/**
	 * @brief Namespace for game representation
	 */
	namespace gfx {
		/**
		 * @brief View
		 * Holds no game data/logic, only SFML data (texture, sprite) and logic (size)
		 */
		class View {
		public:
			using shared = std::shared_ptr<View>;
			using unique = std::unique_ptr<View>;
			using weak = std::weak_ptr<View>;

			/**
			 * @brief Constructs a new View
			 * @param texture_filename The name (and path) of the texture for the View
			 */
			explicit View(std::string texture_filename);

			/**
			 * @brief Displays the given model on the given window
			 * @param window The window the model will be displayed on
			 * @param model The to-be-displayed model
			 * @param fade True if the sprite should be semi transparent, false otherwise
			 * @param debug True if circles should be drawn around sprites, false otherwise
			 * NOTE: debug mode is set in Entity.hpp, recompilation is necessary for it to be turned on
			 * This is intentional, a player shouldn't be able to turn on debug mode
			 * NOTE: the circle drawn around the borders is not indicative of their hitbox
			 * This wasn't change because it wasn't necessary for debugging
			 */
			void display(sf::RenderWindow &window, game::ModelData &model, bool fade, bool debug);

			/**
			 * @brief Returns the texture width in game coordinates (the model's width)
			 * @return The texture width in game coordinates
			 */
			float get_texture_width() const;

			/**
			 * @brief Returns the texture height in game coordinates (the model's height)
			 * @return The texture height in game coordinates
			 */
			float get_texture_height() const;

			/**
			 * @brief Returns the radius of the largest inner circle of the texture (the model's radius)
			 * @return The radius of the texture
			 */
			float get_texture_radius() const;

		private:
			sf::Sprite m_sprite;
			sf::Texture m_texture;
		};

	}
}
