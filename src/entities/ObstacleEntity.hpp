#ifndef OBSTACLE_ENTITY_HPP
#define OBSTACLE_ENTITY_HPP

#include <fstream>
#include <memory>
#include <random>
#include "Entity.hpp"
#include "../utils/json.hpp"
#include "../utils/Stopwatch.hpp"

namespace sff {
	namespace data {
/**
 */
		class ObstacleEntity : public Entity {
		public:
			explicit ObstacleEntity(std::string config_filename);
		};

	}
}

#endif
