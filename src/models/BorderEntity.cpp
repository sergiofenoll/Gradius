#include "BorderEntity.hpp"

namespace sff {
	namespace game {
		BorderEntity::BorderEntity(std::string config_filename, bool bottom) : Entity(config_filename) {

			m_model_data.x_pos = 2.0f;
			if (bottom)
				m_model_data.y_pos = 3 - (m_views[0]->get_texture_height() / 2);
			else
				m_model_data.y_pos = m_views[0]->get_texture_height() / 2;
		}

		void BorderEntity::move() {}

		bool BorderEntity::collides(const Entity::shared other) const {
			auto b_m = m_model_data;
			auto p_m = other->get_model_data();

			float dist_x = std::abs(p_m.x_pos - b_m.x_pos);
			float dist_y = std::abs(p_m.y_pos - b_m.y_pos);

			if (dist_x > ((b_m.width / 2) + p_m.radius)) return false;
			if (dist_y > ((b_m.height / 2) + p_m.radius)) return false;

			if (dist_x <= (b_m.width / 2)) return true;
			if (dist_y <= (b_m.width / 2)) return true;

			return std::pow(dist_x - (b_m.width / 2), 2) + std::pow(dist_y - (b_m.height / 2), 2) <=
				   std::pow(p_m.radius, 2);
		}

		void BorderEntity::fade() {
			m_fade = false;
		}

		bool BorderEntity::is_dead() const {
			return false;
		}
	}
}
