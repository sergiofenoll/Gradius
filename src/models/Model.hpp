#ifndef MODEL_HPP
#define MODEL_HPP

#include <memory>

namespace sff {
	namespace data {
		/**
		 */
		class Model {
		public:
			using unique = std::unique_ptr<Model>;
			using shared = std::shared_ptr<Model>;
			using weak = std::weak_ptr<Model>;

			/**
			 * @brief
			 * @param x
			 * @param y
			 */
			explicit Model(float x = 0.5, float y = 1.5);

			/**
			 * @brief
			 * @return
			 */
			float get_x_pos() const;

			/**
			 * @brief
			 * @return
			 */
			float get_y_pos() const;

			/**
			 * @brief
			 * @return
			 */
			float get_width() const;

			/**
			 * @brief
			 * @return
			 */
			float get_height() const;

			/**
			 * @brief
			 * @return
			 */
			float get_radius() const;

			/**
			 * @brief
			 * @param x_pos
			 */
			void set_x_pos(const float &x_pos);

			/**
			 * @brief
			 * @param y_pos
			 */
			void set_y_pos(const float &y_pos);

			/**
			 * @brief
			 * @param width
			 */
			void set_width(const float &width);

			/**
			 * @brief
			 * @param height
			 */
			void set_height(const float &height);

			/**
			 * @brief
			 * @param radius
			 */
			void set_radius(const float &radius);

			/**
			 * @brief
			 * @param delta_x
			 * @param delta_y
			 */
			void change_pos(float delta_x, double delta_y);
		private:
			float m_x_pos;
			float m_y_pos;
			float m_width;
			float m_height;
			float m_radius;
		};

	}
}

#endif
