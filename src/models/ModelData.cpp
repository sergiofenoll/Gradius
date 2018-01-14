#include "ModelData.hpp"

namespace sff {
	namespace game {
		ModelData::ModelData(int damage, int health, float x_pos, float y_pos, float width, float height, float radius)
				: damage(damage), health(health), x_pos(x_pos), y_pos(y_pos), width(width), height(height),
				  radius(radius) {}

		void ModelData::change_pos(float delta_x, double delta_y) {
			x_pos += delta_x;
			y_pos += delta_y;
		}

	}
}