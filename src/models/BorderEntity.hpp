#ifndef BORDER_ENTITY_HPP
#define BORDER_ENTITY_HPP

#include "Entity.hpp"
#include "../utils/Stopwatch.hpp"

namespace sff {
	namespace game {

		/**
		 * @brief Entity that represents the deadly borders of the game window
		 */
		class BorderEntity : public Entity {
		public:
			using shared = std::shared_ptr<BorderEntity>;
			using unique = std::unique_ptr<BorderEntity>;
			using weak = std::weak_ptr<BorderEntity>;

			/**
			 * @brief Construct a new BorderEntity
			 * @param config_filename The name (and path) of the config file for the BorderEntity
			 * @param bottom True if this is the bottom border, false if is the upper border
			 */
			BorderEntity(std::string config_filename, bool bottom);

			/**
			 * @brief No-op
			 * The border doesn't move, so move() is overridden to do nothing
			 */
			void move() override;

			/**
			 * @brief Checks the collision between this and other
			 * Because the border is a rectangle, collision is detected
			 * using a different algorithm than between two circles
			 * For more information see: https://stackoverflow.com/a/402010/7258143
			 * @param other The other entity that will be used to check collision
			 * @return True if both entities collide, false otherwise
			 */
			bool collides(const Entity::shared other) const override;

			/**
			 * @brief No-op
			 * The border shouldn't fade when hit by the player
			 */
			void fade() override;

			/**
			 * @brief No-op
			 * The border loses health when the player collides with it,
			 * overriding is_dead() makes more sense than constantly
			 * checking for BorderEntities while detecting collision
			 * @return Always false
			 */
			bool is_dead() const override;
		};

	}
}


#endif //GRADIUS_BORDERENTITY_HPP
