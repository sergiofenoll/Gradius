#pragma once

#include <fstream>
#include <memory>
#include <random>
#include "Entity.hpp"
#include "../utils/json.hpp"
#include "../utils/Stopwatch.hpp"

namespace sff {
	namespace game {
		/**
		 * @brief Entity that represents the deadly floating obstacles in space
		 */
		class ObstacleEntity : public Entity {
		public:
			/**
			 * @brief Constructs a new ObstacleEntity
			 * @param config_filename The name (and path) of the config file for the ObstacleEntity
			 */
			explicit ObstacleEntity(std::string config_filename);
		};

	}
}
