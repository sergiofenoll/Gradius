#pragma once

#include <memory>

namespace sff {
	namespace game {
		/**
		 * @brief POD struct for holding Model data
		 * It holds all the game info, no logic is executed inside this struct (except for simple arithmetic)
		 */
		struct ModelData {
			int damage{1};
			int health{1};
			float x_pos{2};
			float y_pos{1.5};
			float width{0.2};
			float height{0.2};
			float radius{0.1};

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
			ModelData(int damage = 1, int health = 1, float x_pos = 2, float y_pos = 1.5, float width = 0.2,
					  float height = 0.2, float radius = 0.1);

			/**
			 * @brief Changes the x- and y position by delta x and delta y respectively
			 * @param delta_x The amount of change for the x position
			 * @param delta_y The amount of change for the y position
			 */
			void change_pos(float delta_x, double delta_y);
		};

	}
}
