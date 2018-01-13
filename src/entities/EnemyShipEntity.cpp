#include "EnemyShipEntity.hpp"

namespace sff {
	namespace data {

		EnemyShipEntity::EnemyShipEntity(std::string config_filename) :
				Entity(config_filename) {
			std::ifstream file;
			try {
				file.open(config_filename);
				if (!file.is_open()) throw(error::FileException(config_filename));
			} catch (std::exception& e) {
				throw e;
			}

			nlohmann::json config;
			try {
				file >> config;
			} catch (std::exception& e) {
				throw error::ConfigFileException(config_filename);
			}

			try {
				m_fires = config["fires"];
			} catch (std::exception& e) {
				m_fires = false;
			}
			try {
				if (m_fires) {
					try {
						m_bullet_config_filename = config["bullet_config_file"];
					} catch (std::exception& e) {
						throw error::ConfigFileException(config_filename, "bullet_texture");
					}

					try {
						m_ticks_between_bullets = config["ticks_between_bullets"];
					} catch (std::exception& e) {
						throw error::ConfigFileException(config_filename, "ticks_between_bullets");
					}
				}
			} catch(error::FileException& e) {
				std::cout << e.what() << std::endl;
				m_fires = false;
			}

			std::random_device r; // Setup random seed
			std::mt19937 mt(r()); // Create a PRNG eninge (using the Mersenne twister algorithm)

			std::uniform_real_distribution<float> x_dist(4.5, 9.0);
			m_model->set_x_pos(x_dist(mt));

			std::uniform_real_distribution<float> y_dist(0.5, 2.5);
			m_model->set_y_pos(y_dist(mt));
		}

		void EnemyShipEntity::fire(std::list<Entity::shared> &entities) {
			if (!m_fires) return;
			if (m_tick == m_ticks_between_bullets) {
				m_tick = 0;
				double x = m_model->get_x_pos();
				double y = m_model->get_y_pos();
				try {
					entities.push_back(std::make_shared<BulletEntity>(m_bullet_config_filename, x, y));
				} catch (std::exception& e) {
					std::cout << e.what() << std::endl;
				}
				return;
			}
			if (m_tick < m_ticks_between_bullets) ++m_tick;
		}

		void EnemyShipEntity::collided() {
			m_collided = true;
		}

	}
}
