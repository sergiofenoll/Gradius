#include "ObstacleEntity.hpp"

namespace sff {
	namespace data {
		ObstacleEntity::ObstacleEntity(std::string config_filename) : Entity(config_filename) {
			std::random_device r; // Setup random seed
			std::mt19937 mt(r()); // Create a PRNG eninge (using the Mersenne twister algorithm)

			std::uniform_real_distribution<float> x_dist(4.5, 8.0);
			m_model->set_x_pos(x_dist(mt));

			std::uniform_real_distribution<float> y_dist(0.5, 2.5);
			m_model->set_y_pos(y_dist(mt));

		}
	}
}