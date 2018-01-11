#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <memory>
#include "../models/Model.hpp"

namespace sff
{
namespace logic
{

class Controller
{
public:
	using shared = std::shared_ptr<Controller>;
	using unique = std::unique_ptr<Controller>;
	using weak = std::weak_ptr<Controller>;
	/**
	 */
	Controller() = default;
	/**
	 */
	void move(data::Model& model, double delta_x, double delta_y) { model.change_pos(delta_x, delta_y); };
	/**
	 */
	void fire(data::Model& model) {};
};

}
}

#endif
