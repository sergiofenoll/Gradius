#include "Model.hpp"

namespace sff {
	namespace data {
		Model::Model(float x, float y)  : m_x_pos(x), m_y_pos(y), m_radius(0) {}

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

		void Model::set_x_pos(const float &x_pos) {
			m_x_pos = x_pos;
		}

		void Model::set_y_pos(const float &y_pos) {
			m_y_pos = y_pos;
		}

		void Model::set_width(const float &width) {
			m_width = width;
		}

		void Model::set_height(const float &height) {
			m_height = height;
		}

		void Model::set_radius(const float &radius) {
			m_radius = radius;
		}

		void Model::change_pos(float delta_x, double delta_y) {
			m_x_pos += delta_x;
			m_y_pos += delta_y;
		}

	}
}