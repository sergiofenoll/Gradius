#include "BorderEntity.hpp"

namespace sff {
	namespace data {
		BorderEntity::BorderEntity(std::string config_filename, bool second) : Entity(config_filename) {

			m_model->set_x_pos(2.0f);
			if (second)
				m_model->set_y_pos(3 - (m_views[0]->get_texture_y() / 2));
			else
				m_model->set_y_pos(m_views[0]->get_texture_y() / 2);
		}

		void BorderEntity::move() {}

		bool BorderEntity::intersects(const Entity::shared other) const {
			auto b_m = get_model_obj();
			auto p_m = other->get_model_obj();

			float dist_x = std::abs(p_m.get_x_pos() - b_m.get_x_pos());
			float dist_y = std::abs(p_m.get_y_pos() - b_m.get_y_pos());

			if (dist_x > ((b_m.get_width() / 2) + p_m.get_radius())) return false;
			if (dist_y > ((b_m.get_height() / 2) + p_m.get_radius())) return false;

			if (dist_x <= (b_m.get_width() / 2)) return true;
			if (dist_y <= (b_m.get_height() / 2)) return true;

			return std::pow(dist_x - (b_m.get_width() / 2), 2) + std::pow(dist_y - (b_m.get_height() / 2), 2) <=
				   std::pow(p_m.get_radius(), 2);
		}

		bool BorderEntity::is_dead() const {
			return false;
		}
	}
}
