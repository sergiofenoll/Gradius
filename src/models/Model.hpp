#ifndef MODEL_HPP
#define MODEL_HPP

#include <memory>

namespace sff
{
namespace data
{
/**
 */
class Model
{
public:
	using unique = std::unique_ptr<Model>;
	using shared = std::shared_ptr<Model>;
	using weak = std::weak_ptr<Model>;
	/**
	 */
	explicit Model(float x = 0.0, float y = 1.5, float radius = 0.05) : m_x_pos(x), m_y_pos(y), m_radius(radius) {};
	/**
	 */
	float get_x_pos() const { return m_x_pos; };
	/**
	 */
	float get_y_pos() const { return m_y_pos; };
	/**
	 *
	 * @return
	 */
	float get_radius() const { return m_radius; };
	/**
	 *
	 * @param x_pos
	 */
	void set_x_pos(float x_pos) { m_x_pos = x_pos; };
	/**
	 *
	 * @param y_pos
	 */
	void set_y_pos(float y_pos) { m_y_pos = y_pos; };
	/**
	 *
	 * @param radius
	 */
	void set_radius(float radius) {m_radius = radius; };
	/**
	 *
	 * @param delta_x
	 * @param delta_y
	 */
	void change_pos(float delta_x, double delta_y)
	{
		m_x_pos += delta_x;
		m_y_pos += delta_y;
	};
private:
	float m_x_pos;
	float m_y_pos;
	float m_radius;
};

}
}

#endif
