#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include "../models/Model.hpp"
#include "../views/View.hpp"

namespace sff
{
namespace data
{
/**
 */
class Entity
{
public:
	/**
	 */
	Entity();
	/**
	 */
	void notify();
private:
	Model::unique_ptr m_model;
	std::vector<gfx::View::weak_ptr> m_observers;
	
};

}
}

#endif
