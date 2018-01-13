#include "Entity.hpp"

namespace sff {
	namespace data {
		Entity::Entity(std::string config_filename) : m_model(std::make_unique<Model>()) {
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

			std::string texture;
			try {
				texture = config["texture"];
			} catch (std::exception& e) {}

			try {
				m_views.push_back(std::make_shared<gfx::View>(texture));
			} catch (std::exception& e) {}

			try {
				m_health = config["health"];
			} catch (std::exception& e) {}

			try {
				m_damage = config["damage"];
			} catch (std::exception& e) {}

			float speed;
			try {
				speed = config["speed"];
			} catch (std::exception& e) {
				speed = 1;
			}
			m_delta_x = speed / utils::Stopwatch::get_instance().get_fps();
			m_delta_y = 0;

			m_model->set_radius(m_views[0]->get_texture_radius());
			m_model->set_width(m_views[0]->get_texture_x());
			m_model->set_height(m_views[0]->get_texture_y());
		};

		void Entity::notify(sf::RenderWindow &window) {
			if (m_collision_tick == 60) {
				m_collision_tick = 0;
				m_collided = false;
			}
			if (m_collided and m_collision_tick < 60) ++m_collision_tick;
			for (auto view : m_views)
				view->display(*m_model, window, m_collided, m_debug);
		}

		void Entity::move() {
			m_model->change_pos(-m_delta_x, m_delta_y);
		}

		void Entity::fire(std::list<Entity::shared> &entities) {}

		bool Entity::intersects(const Entity::shared other) const {
			if (m_collided) return false;
			auto m1 = get_model_obj();
			auto m2 = other->get_model_obj();
			return std::pow(m2.get_x_pos() - m1.get_x_pos(), 2) + std::pow(m2.get_y_pos() - m1.get_y_pos(), 2) <=
				   std::pow(m1.get_radius() + m2.get_radius(), 2);
		}

		void Entity::collided() {
			m_collided = false;
		}

		bool Entity::is_dead() const {
			 return m_model->get_x_pos() < (0 - m_views[0]->get_texture_x()) or m_health <= 0;
		}

		Model Entity::get_model_obj() const {
			return *m_model;
		}

		int Entity::get_health() const {
			return m_health;
		}

		int Entity::get_damage() const {
			return m_damage;
		}

		void Entity::set_health(const int &health) {
			m_health = health;
		}
	}
}