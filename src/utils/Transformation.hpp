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
	 *
	 * @param width
	 * @param height
	 */
	void set_resolution(unsigned int width, unsigned int height)
	{
		m_window_width = width;
		m_window_height = height;
	}
	/**
	 */
	PixelPosition transform(CoordPosition coords) const
	{
		auto x_pix = static_cast<unsigned int>((coords.x / m_max_x_coor) * m_window_width);
		auto y_pix = static_cast<unsigned int>((coords.y / m_max_y_coor) * m_window_height);
		return PixelPosition(x_pix, y_pix);
	};
	/**
	 *
	 */
	CoordPosition transform(PixelPosition pixels) const
	{
		auto x_coord = ((double) pixels.x / (double) m_window_width) * m_max_x_coor;
		auto y_coord = ((double) pixels.y / (double) m_window_height) * m_max_y_coor;
		return CoordPosition(x_coord, y_coord);
	};
private:
	/**
	 */
	Transformation() = default;
	float m_max_x_coor = 4.0;
	float m_max_y_coor = 3.0;
	unsigned int m_window_width {800};
	unsigned int m_window_height {600};
};

}
}

#endif
