#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cmath>
#include <fstream>
#include <iostream>
#include <memory>
#include <list>
#include "../models/Model.hpp"
#include "../views/View.hpp"
#include "../utils/json.hpp"
#include "../utils/Stopwatch.hpp"

namespace sff {

	namespace data {
/**
 * @brief
 */
		class Entity {
		public:
			using shared = std::shared_ptr<Entity>;
			using unique = std::unique_ptr<Entity>;
			using weak = std::weak_ptr<Entity>;

			/**
			 * @brief
			 */
			explicit Entity(std::string config_filename);

			/**
			 * @brief
			 */
			virtual ~Entity() = default;

			/**
			 * @brief
			 * @param window
			 */
			void notify(sf::RenderWindow &window);

			/**
			 * @brief
			 */
			virtual void move();

			/**
			 *
			 * @param entities
			 */
			virtual void fire(std::list<Entity::shared> &entities);

			/**
			 * @brief
			 * @param other
			 * @return
			 */
			virtual bool intersects(const Entity::shared other) const;

			/**
			 * @brief
			 */
			virtual void collided();

			/**
			 * @brief
			 * @return
			 */
			virtual bool is_dead() const;

			/**
			 *
			 * @return
			 */
			Model get_model_obj() const;

			/**
			 *
			 * @return
			 */
			int get_health() const;

			/**
			 *
			 * @return
			 */
			int get_damage() const;

			/**
			 *
			 * @param health
			 */
			void set_health(const int &health);

		protected:
			Model::unique m_model;
			std::vector<gfx::View::shared> m_views;
			float m_delta_x{0};
			float m_delta_y{0};
			int m_damage{1};
			int m_health{1};

			int m_collision_tick{0};
			bool m_collided{false};

			bool m_debug{true};
		};

	}
}

#endif
