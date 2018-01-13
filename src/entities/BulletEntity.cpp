#include "BulletEntity.hpp"

namespace sff {
	namespace data {
		BulletEntity::BulletEntity(std::string config_filename, float pos_x, float pos_y) : Entity(config_filename) {
			std::ifstream file;
			try {
				file.open(config_filename);
				if (!file.is_open()) throw(error::FileException(config_filename));
			} catch (std::exception& e) {
				throw;
			}

			nlohmann::json config;
			try {
				file >> config;
			} catch (std::exception& e) {
				throw error::ConfigFileException(config_filename);
			}

			try {
				m_friendly = config["friendly"];
			} catch (std::exception& e) {
				m_friendly = true;
			}

			m_model->set_x_pos(pos_x);
			m_model->set_y_pos(pos_y);
		}

		void BulletEntity::move() {
			m_model->change_pos((m_friendly ? m_delta_x : -m_delta_x), m_delta_y);
		}

		bool BulletEntity::is_dead() const {
			auto x_pos = m_model->get_x_pos();
			if (m_friendly)
				return (x_pos > 4) or m_health <= 0;
			else
				return (x_pos < 0) or m_health <= 0;
		}
	}
}