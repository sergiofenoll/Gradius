#include "Entity.hpp"

namespace sff {
	namespace data {
		Entity::Entity(std::string config_filename) {
			std::ifstream file(config_filename);
			if (!file.is_open()) throw (error::FileOpenException(config_filename));

			nlohmann::json config;
			try {
				file >> config;
			} catch (std::exception &e) {
				throw error::ParserOpenException(config_filename);
			}

			int damage;
			int health;

			float speed{1};
			std::string texture{};
			try {
				try {
					texture = config["texture"];
				} catch (...) {
					throw error::ParserFieldException(config_filename, "texture");
				}

				try {
					health = config["health"];
				} catch (...) {
					throw error::ParserFieldException(config_filename, "health");
				}

				try {
					damage = config["damage"];
				} catch (...) {
					throw error::ParserFieldException(config_filename, "damage");
				}

				try {
					speed = config["speed"];
				} catch (...) {
					speed = 1;
					throw error::ParserFieldException(config_filename, "speed");
				}
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			m_views.push_back(std::make_shared<gfx::View>(texture));

			m_delta_x = speed / utils::Stopwatch::get_instance().get_fps();
			m_delta_y = 0;

			m_model = std::make_unique<Model>(damage, health, 0, 0, m_views[0]->get_texture_width(),
											  m_views[0]->get_texture_height(), m_views[0]->get_texture_radius());
		};

		void Entity::notify(sf::RenderWindow &window) {
			if (m_fade_tick == 60) {
				m_fade_tick = 0;
				m_fade = false;
			}
			if (m_fade and m_fade_tick < 60) ++m_fade_tick;
			for (auto view : m_views)
				view->display(window, *m_model, m_fade, m_debug);
		}

		void Entity::move() {
			m_model->change_pos(-m_delta_x, m_delta_y);
		}

		void Entity::fire(std::list<Entity::shared> &bullets) {}

		bool Entity::collides(const Entity::shared other) const {
			if (m_fade) return false;
			auto m1 = *m_model;
			auto m2 = *(other->m_model);
			return std::pow(m2.get_x_pos() - m1.get_x_pos(), 2) + std::pow(m2.get_y_pos() - m1.get_y_pos(), 2) <=
				   std::pow(m1.get_radius() + m2.get_radius(), 2);
		}

		void Entity::fade() {
			m_fade = true;
		}

		bool Entity::is_dead() const {
			return m_model->get_x_pos() < (0 - m_views[0]->get_texture_width()) or get_health() <= 0;
		}

		Model Entity::get_model() const {
			return *m_model;
		}

		int Entity::get_health() const {
			return m_model->get_health();
		}

		int Entity::get_damage() const {
			return m_model->get_damage();
		}

		void Entity::set_health(const int &health) {
			m_model->set_health(health);
		}
	}
}