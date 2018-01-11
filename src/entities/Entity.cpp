#include "Entity.hpp"

namespace sff
{
namespace data
{

void Entity::notify(sf::RenderWindow& window)
{
	for (auto view : m_views)
	{
		view->display(*m_model, window);
	}
}

}
}
