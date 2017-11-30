#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <vector>
#include "../views/View.hpp"

namespace sff
{
namespace data
{

class Entity
{
public:
	void notify() const;
private:
	double m_x_pos;
	double m_y_pos;
	std::vector<std::weak_ptr<gfx::View>> m_views;
};

}
}

#endif
