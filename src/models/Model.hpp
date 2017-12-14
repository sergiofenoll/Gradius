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
	using unique_ptr = std::unique_ptr<Model>;
private:
	double m_x_pos;
	double m_y_pos;
};

}
}

#endif
