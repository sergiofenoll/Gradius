#include "BulletEntity.hpp"

namespace sff {
	namespace data {
		BulletEntity::BulletEntity(std::string config_filename, float pos_x, float pos_y) : Entity(config_filename) {
			std::ifstream file(config_filename);
			if (!file.is_open()) throw (error::FileOpenException(config_filename));

			nlohmann::json config;
			try {
				file >> config;
			} catch (...) {
				throw error::ParserOpenException(config_filename);
			}

			try {
				try {
					m_friendly = config["friendly"];
				} catch (...) {
					m_friendly = true;
					throw error::ParserFieldException(config_filename, "friendly");
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			m_model->set_x_pos(pos_x);
			m_model->set_y_pos(pos_y);
		}

		void BulletEntity::move() {
			m_model->change_pos((m_friendly ? m_delta_x : -m_delta_x), m_delta_y);
		}

		void BulletEntity::fade() {
			m_fade = false;
		}

		bool BulletEntity::is_dead() const {
			auto x_pos = m_model->get_x_pos();
			if (m_friendly)
				return (x_pos > 4) or get_health() <= 0;
			else
				return (x_pos < 0) or get_health() <= 0;
		}
	}
}