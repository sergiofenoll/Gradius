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
	explicit Model(double x = 0.0, double y = 1.5) : m_x_pos(x), m_y_pos(y) {};
	/**
	 */
	double get_x_pos() const { return m_x_pos; };
	/**
	 */
	double get_y_pos() const { return m_y_pos; };
	/**
	 */
	void set_x_pos(double x_pos) { m_x_pos = x_pos; };
	/**
	 */
	void set_y_pos(double y_pos) { m_y_pos = y_pos; };
	/**
	 */
	void change_pos(double delta_x, double delta_y)
	{
		m_x_pos += delta_x;
		m_y_pos += delta_y;
	};
private:
	double m_x_pos;
	double m_y_pos;
};

}
}

#endif
