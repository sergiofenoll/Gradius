#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <memory>
#include "../models/Model.hpp"
#include "../views/View.hpp"

namespace sff
{

namespace data
{
/**
 * @brief
 */
class Entity
{
public:
	using shared = std::shared_ptr<Entity>;
	using unique = std::unique_ptr<Entity>;
	using weak = std::weak_ptr<Entity>;
	/**
	 * @brief
	 * @param controller
	 */
	explicit Entity() : m_model(std::make_unique<Model>()) {};

	/**
	 * @brief
	 */
	virtual ~Entity() = default;

	/**
	 * @brief
	 * @param window
	 */
	void notify(sf::RenderWindow &window) { for (auto view : m_views) view->display(*m_model, window, m_debug); };

	/**
	 * @brief
	 */
	virtual void move() { m_model->change_pos(-m_delta_x, m_delta_y); };

	/**
	 *
	 * @param entities
	 */
	virtual void fire(std::vector<Entity::shared>& entities) {};

	/**
	 * @brief
	 * @return
	 */
	virtual bool is_dead() const { return m_model->get_x_pos() < 0 or m_health <= 0; };

	/**
	 *
	 * @return
	 */
	Model get_model_obj() const { return *m_model; };

	/**
	 *
	 * @return
	 */
	int get_health() const { return m_health; };

	/**
	 *
	 * @return
	 */
	int get_damage() const { return m_damage; };

	/**
	 *
	 * @param health
	 */
	void set_health(const int& health) { m_health = health; };

protected:
	Model::unique m_model;
	std::vector<gfx::View::shared> m_views;
	float m_delta_x {0};
	float m_delta_y {0};
	int m_damage {1};
	int m_health {1};

	std::string m_bullet_texture {};
	int m_bullet_damage {0};
	float m_bullet_speed {0};
	bool m_friendly {false};

	bool m_debug {true};
};

}
}

#endif
