#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>
#include <thread>
#include "Singleton.hpp"

namespace sff {

	namespace utils {

/**
 */
		class Stopwatch : public Singleton<Stopwatch> {
			friend class Singleton<Stopwatch>;

		public:
			/**
			 *
			 */
			void start() {
				m_start_time = std::chrono::high_resolution_clock::now();
			};

			/**
			 *
			 */
			void end() {
				std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - m_start_time;
				if (duration < m_tick_length)
					std::this_thread::sleep_for(m_tick_length - duration);
			};

			/**
			 *
			 * @return
			 */
			float get_fps() { return 60.0; };
		private:
			/**
			 */
			Stopwatch() = default;

			std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time;
			std::chrono::microseconds m_tick_length{16700};
		};

	}

}

#endif
