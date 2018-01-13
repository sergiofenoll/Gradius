#ifndef SINGLETON_HPP
#define SINGLETON_HPP

namespace sff {
	namespace utils {
/**
 */
		template<typename T>
		class Singleton {
		public:
			/**
			 */
			Singleton(const Singleton &) = delete;

			/**
			 */
			Singleton &operator=(const Singleton &) = delete;

			/**
			 */
			static T &get_instance() {
				static T instance;
				return instance;
			}

		protected:
			/**
			 */
			Singleton() = default;

			/**
			 */
			~Singleton() = default;
		};
	}
}

#endif
