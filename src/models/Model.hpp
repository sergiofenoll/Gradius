#pragma once

#include <memory>

namespace sff {
	namespace data {
		/**
		 * @brief Model
		 * It holds all the game info, no logic is executed inside this class
		 * (except for simple arithmetic and getters/setters)
		 */
		class Model {
		public:
			using unique = std::unique_ptr<Model>;
			using shared = std::shared_ptr<Model>;
			using weak = std::weak_ptr<Model>;

			/**
			 * @brief Constructs a new Model
			 * @param damage The damage caused by the model
			 * @param health The health of the model
			 * @param x_pos The X coordinate (game coordinates) of the model
			 * @param y_pos The Y coordinate (game coordinates) of the model
			 * @param width The width (game units) of the model
			 * @param height The height (game units) of the model
			 * @param radius The radius (game units) of the model
			 */
			Model(int damage, int health, float x_pos, float y_pos, float width, float height, float radius);

			/**
			 * @brief Returns the damage caused by the model
			 * @return The damage caused by the model
			 */
			int get_damage() const;

			/**
			 * @brief Returns the model's health
			 * @return The model's health
			 */
			int get_health() const;

			/**
			 * @brief Returns the model's x position
			 * @return The model's x position
			 */
			float get_x_pos() const;

			/**
			 * @brief Returns the model's y position
			 * @return The model's y position
			 */
			float get_y_pos() const;

			/**
			 * @brief Returns the model's width
			 * @return The model's width
			 */
			float get_width() const;

			/**
			 * @brief Returns the model's height
			 * @return The model's height
			 */
			float get_height() const;

			/**
			 * @brief Returns the model's radius
			 * @return The model's radius
			 */
			float get_radius() const;

			/**
			 * @brief Sets the health of the model
			 * @param health The new health of the model
			 */
			void set_health(const int &health);

			/**
			 * @brief Sets the new x position of the model
			 * @param x_pos The new x position of the model
			 */
			void set_x_pos(const float &x_pos);

			/**
			 * @brief Sets the new y position of the model
			 * @param y_pos The new y position of the model
			 */
			void set_y_pos(const float &y_pos);

			/**
			 * @brief Changes the x- and y position by delta x and delta y respectively
			 * @param delta_x The amount of change for the x position
			 * @param delta_y The amount of change for the y position
			 */
			void change_pos(float delta_x, double delta_y);

		private:
			int m_damage;
			int m_health;
			float m_x_pos;
			float m_y_pos;
			float m_width;
			float m_height;
			float m_radius;
		};

	}
}
