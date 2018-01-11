#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include <SFML/Graphics.hpp>
#include "Singleton.hpp"

namespace sff
{
namespace utils
{
/**
 */
struct PixelPosition
{
	/**
	 *
	 * @param x
	 * @param y
	 */
	explicit PixelPosition(unsigned int x, unsigned int y) : x(x), y(y) {};
	unsigned int x;
	unsigned int y;
};
/**
 */
struct CoordPosition
{
	/**
	 *
	 * @param x
	 * @param y
	 */
	explicit CoordPosition(double x, double y) : x(x), y(y) {};
	double x;
	double y;
};
/**
 */
class Transformation : public Singleton<Transformation>
{
public:
	friend class Singleton<Transformation>;
	/**
	 */
	PixelPosition transform(const sf::RenderWindow& window, CoordPosition coords) const
	{
		sf::Vector2u window_size = window.getSize();
		auto x_pix = static_cast<unsigned int>((coords.x / m_max_x_coor) * window_size.x);
		auto y_pix = static_cast<unsigned int>((coords.y / m_max_y_coor) * window_size.y);
		return PixelPosition(x_pix, y_pix);
	}
private:
	/**
	 */
	Transformation() = default;
	double m_max_x_coor = 4.0;
	double m_max_y_coor = 3.0;
};

}
}

#endif
