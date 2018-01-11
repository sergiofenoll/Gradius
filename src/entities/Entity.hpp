#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <memory>
#include "../models/Model.hpp"
#include "../views/View.hpp"
#include "../controllers/Controller.hpp"

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
	enum class Key { UP, DOWN, LEFT, RIGHT, SPACE, NONE};
	/**
	 * @brief
	 * @param controller
	 */
	explicit Entity(logic::Controller::shared controller)
			: m_model(std::make_unique<Model>()), m_controller(controller) {};
	/**
	 * @brief
	 */
	virtual ~Entity() = default;
	/**
	 * @brief
	 * @param window
	 */
	void notify(sf::RenderWindow& window);
	/**
	 * @brief
	 * @param key
	 */
	virtual void control(const Key& key) = 0;
	/**
	 * @brief
	 * @return
	 */
	bool is_dead() const { return m_dead; };
	/**
	 * @brief
	 * @param controller
	 */
	void set_controller(logic::Controller::weak controller) { m_controller = controller; };
protected:
	Model::unique m_model;
	logic::Controller::weak m_controller;
	std::vector<gfx::View::shared> m_views;
	bool m_dead {false};
};

}
}

#endif
