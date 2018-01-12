#ifndef BULLET_ENTITY_HPP
#define BULLET_ENTITY_HPP

#include <memory>
#include <string>
#include "Entity.hpp"
#include "../utils/Stopwatch.hpp"

namespace sff
{
namespace data
{
/**
 */
class BulletEntity : public Entity
{
public:
	/**
	 */
	BulletEntity(std::string texture_filename, float speed, unsigned int damage, float pos_x, float pos_y, bool friendly)
	{
		m_views.push_back(std::make_shared<gfx::View>(texture_filename));

		m_delta_x = speed / utils::Stopwatch::get_instance().get_fps();
		m_damage = damage;
		m_friendly = friendly;
		m_model->set_x_pos(pos_x);
		m_model->set_y_pos(pos_y);
	};
	/**
	 * @brief
	 */
	virtual void move(Directions directions = {}) { m_model->change_pos((m_friendly ? m_delta_x : -m_delta_x), m_delta_y); };
	/**
	 *
	 * @return
	 */
	bool is_dead() const override { return m_model->get_x_pos() > 4 or m_health <= 0; };
private:
	bool m_friendly;
};

}
}

#endif
