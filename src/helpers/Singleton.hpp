#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>

namespace sff
{

template <typename T>
class Singleton
{
public:
	std::weak_ptr<T> get_instance();
private:
	std::unique_ptr<T> m_instance;
};

template <typename T>
std::weak_ptr<T> Singleton<T>::get_instance()
{
	return std::weak_ptr<T>(m_instance);
}

}

#endif
