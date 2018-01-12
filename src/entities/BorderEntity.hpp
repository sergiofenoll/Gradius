//
// Created by uauser on 1/12/18.
//

#ifndef GRADIUS_BORDERENTITY_HPP
#define GRADIUS_BORDERENTITY_HPP

#include "Entity.hpp"
#include "../utils/Stopwatch.hpp"

namespace sff
{
namespace data {

class BorderEntity : Entity {
public:
	/**
	 */
	BorderEntity(std::string texture_filename, float pos_x, float pos_y)
	{
		m_views.push_back(std::make_shared<gfx::View>(texture_filename));

		m_delta_x = 0.01 / utils::Stopwatch::get_instance().get_fps();
		m_damage = 2;
		m_model->set_x_pos(pos_x);
		m_model->set_y_pos(pos_y);
		auto game_coords = utils::Transformation::get_instance().transform(
				utils::PixelPosition(m_views[0]->get_max_texture_size() / 2, 0));
		m_model->set_radius(game_coords.x);
	};
	/**
	 * @brief
	 */
	void move() override {};
	/**
	 *
	 * @return
	 */
	bool is_dead() const override { return false; };
};

}
}


#endif //GRADIUS_BORDERENTITY_HPP
