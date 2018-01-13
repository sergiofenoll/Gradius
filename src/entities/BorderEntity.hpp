#ifndef BORDER_ENTITY_HPP
#define BORDER_ENTITY_HPP

#include "Entity.hpp"
#include "../utils/Stopwatch.hpp"

namespace sff {
	namespace data {

		/**
		 * @brief
		 */
		class BorderEntity : public Entity {
		public:
			using shared = std::shared_ptr<BorderEntity>;
			using unique = std::unique_ptr<BorderEntity>;
			using weak = std::weak_ptr<BorderEntity>;
			/**
			 * @brief
			 */
			explicit BorderEntity(std::string texture_filename, bool second);

			/**
			 * @brief
			 */
			void move() override;

			bool intersects(const Entity::shared other) const override;

			/**
			 *
			 * @return
			 */
			bool is_dead() const override;
		};

	}
}


#endif //GRADIUS_BORDERENTITY_HPP
