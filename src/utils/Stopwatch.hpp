#pragma once

#include <chrono>
#include <thread>
#include "Singleton.hpp"

namespace sff {

	namespace utils {

		/**
		 * @brief An implementation of a Stopwatch
		 * FPS is set to 60, because there were no requirements regarding variable FPS
		 * and it seemed easier this way
		 */
		class Stopwatch : public Singleton<Stopwatch> {
			friend class Singleton<Stopwatch>;

		public:
			/**
			 * @brief Starts the stopwatch
			 */
			void start() {
				m_start_time = std::chrono::high_resolution_clock::now();
			};

			/**
			 * @brief Stops the stopwatch and sleeps until the tick length has been reached
			 */
			void end() {
				std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - m_start_time;
				if (duration < m_tick_length)
					std::this_thread::sleep_for(m_tick_length - duration);
			};

			/**
			 * @brief Returns the FPS
			 * @return The FPS
			 */
			float get_fps() { return 60.0; };

		private:
			Stopwatch() = default;

			std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time;
			std::chrono::microseconds m_tick_length{16700};
		};

	}

}
