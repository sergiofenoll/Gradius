#pragma once

namespace sff {
	namespace utils {
		/**
		 * @brief An implementation of the Singleton pattern using templates
		 * Shamelessly taken from: https://stackoverflow.com/questions/41328038/singleton-template-as-base-class-in-c
		 * @tparam T The template of the class that will be a Singleton
		 */
		template<typename T>
		class Singleton {
		public:
			Singleton(const Singleton &) = delete;

			Singleton &operator=(const Singleton &) = delete;

			/**
			 * @brief Returns the single instance of the object
			 * @return A static reference to the object
			 */
			static T &get_instance() {
				static T instance;
				return instance;
			}

		protected:
			Singleton() = default;

			~Singleton() = default;
		};
	}
}
