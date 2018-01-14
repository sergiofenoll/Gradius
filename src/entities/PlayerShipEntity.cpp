#include "PlayerShipEntity.hpp"

namespace sff {
	namespace data {

		PlayerShipEntity::PlayerShipEntity(std::string config_filename) :
				Entity(config_filename) {
			std::ifstream file(config_filename);
			if (!file.is_open()) throw (error::FileOpenException(config_filename));

			nlohmann::json config;
			try {
				file >> config;
			} catch (std::exception &e) {
				throw error::ParserOpenException(config_filename);
			}

			try {
				try {
					m_bullet_config_filename = config["bullet_config_file"];
				} catch (...) {
					throw error::ParserFieldException(config_filename, "bullet_config_file");
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			m_delta_y = m_delta_x;
			m_model->set_x_pos(0.5);
			m_model->set_y_pos(1.5);
		}

		void PlayerShipEntity::move() {

			if (m_actions.up and (m_model->get_y_pos() - m_delta_y) > (0 + m_model->get_radius()))
				m_model->change_pos(0, -m_delta_y);
			if (m_actions.down and (m_model->get_y_pos() + m_delta_y) < (3 - m_model->get_radius()))
				m_model->change_pos(0, m_delta_y);
			if (m_actions.left and (m_model->get_x_pos() - m_delta_x) > (0 + m_model->get_radius()))
				m_model->change_pos(-m_delta_x, 0);
			if (m_actions.right and (m_model->get_x_pos() + m_delta_x) < (4 - m_model->get_radius()))
				m_model->change_pos(m_delta_x, 0);
		}

		void PlayerShipEntity::fire(std::list<Entity::shared> &bullets) {
			if (m_bullet_config_filename.empty()) return;
			if (m_actions.fire and m_tick == m_ticks_between_bullets) {
				m_tick = 0;
				double x = m_model->get_x_pos();
				double y = m_model->get_y_pos();
				try {
					bullets.push_back(std::make_shared<BulletEntity>(m_bullet_config_filename, x, y));
				} catch (std::exception &e) {
					std::cout << e.what() << std::endl;
				}
				return;
			}
			if (m_tick < m_ticks_between_bullets) ++m_tick;
		}

		void PlayerShipEntity::fade() {
			m_fade = true;
			m_model->set_x_pos(0.5);
			m_model->set_y_pos(1.5);
		}

		bool PlayerShipEntity::is_dead() const {
			return get_health() <= 0;
		}

		Actions &PlayerShipEntity::actions() {
			return m_actions;
		}

	}
}
