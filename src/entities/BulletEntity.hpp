#ifndef BULLET_ENTITY_HPP
#define BULLET_ENTITY_HPP

#include <memory>
#include <string>
#include "Entity.hpp"
#include "../utils/Stopwatch.hpp"
#include "../exceptions/FileException.hpp"

namespace sff {
	namespace data {
/**
 */
		class BulletEntity : public Entity {
		public:
			/**
			 */
			BulletEntity(std::string config_filename, float pos_x, float pos_y);

			/**
			 * @brief
			 */
			void move() override;

			/**
			 *
			 * @return
			 */
			bool is_dead() const override;

		private:
			bool m_friendly{true};
		};

	}
}

#endif
