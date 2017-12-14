#ifndef VIEW_HPP
#define VIEW_HPP

#include <memory>
#include <SFML/Graphics.hpp>

namespace sff
{
namespace gfx
{

class View
{
public:
	using weak_ptr = std::weak_ptr<View>;
private:
	sf::Sprite m_sprite;
};

}
}

#endif
