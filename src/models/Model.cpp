#include "Model.hpp"

namespace sff {
	namespace data {
		Model::Model(int damage, int health, float x_pos, float y_pos, float width, float height, float radius)
				: m_damage(damage), m_health(health), m_x_pos(x_pos), m_y_pos(y_pos), m_width(width), m_height(height),
				  m_radius(radius) {}

		int Model::get_damage() const {
			return m_damage;
		}

		int Model::get_health() const {
			return m_health;
		}

		float Model::get_x_pos() const {
			return m_x_pos;
		}

		float Model::get_y_pos() const {
			return m_y_pos;
		}

		float Model::get_width() const {
			return m_width;
		}

		float Model::get_height() const {
			return m_height;
		}

		float Model::get_radius() const {
			return m_radius;
		}

		void Model::set_health(const int &health) {
			m_health = health;
		}

		void Model::set_x_pos(const float &x_pos) {
			m_x_pos = x_pos;
		}

		void Model::set_y_pos(const float &y_pos) {
			m_y_pos = y_pos;
		}

		void Model::change_pos(float delta_x, double delta_y) {
			m_x_pos += delta_x;
			m_y_pos += delta_y;
		}

	}
}