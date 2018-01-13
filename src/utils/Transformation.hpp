#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include <SFML/Graphics.hpp>
#include "Singleton.hpp"

namespace sff {
	namespace utils {
/**
 */
		struct PixelPosition {
			/**
			 *
			 * @param x
			 * @param y
			 */
			explicit PixelPosition(unsigned int x, unsigned int y) : x(x), y(y) {};
			unsigned int x;
			unsigned int y;
		};

/**
 */
		struct CoordPosition {
			/**
			 *
			 * @param x
			 * @param y
			 */
			explicit CoordPosition(float x, float y) : x(x), y(y) {};
			float x;
			float y;
		};

/**
 */
		class Transformation : public Singleton<Transformation> {
		public:
			friend class Singleton<Transformation>;

			/**
			 *
			 * @param width
			 * @param height
			 */
			void set_resolution(unsigned int width, unsigned int height) {
				m_window_width = width;
				m_window_height = height;
			}

			/**
			 */
			PixelPosition transform(CoordPosition coords) const {
				auto x_pix = static_cast<unsigned int>((coords.x / m_max_x_coor) * m_window_width);
				auto y_pix = static_cast<unsigned int>((coords.y / m_max_y_coor) * m_window_height);
				return PixelPosition(x_pix, y_pix);
			};

			/**
			 *
			 */
			CoordPosition transform(PixelPosition pixels) const {
				auto x_coord = ((float) pixels.x / (float) m_window_width) * m_max_x_coor;
				auto y_coord = ((float) pixels.y / (float) m_window_height) * m_max_y_coor;
				return CoordPosition(x_coord, y_coord);
			};

			/**
			 * @brief
			 * @param x
			 * @return
			 */
			unsigned int transform_x(float x) const {
				return static_cast<unsigned int>(x / m_max_x_coor) * m_window_width;
			};

			/**
			 * @brief
			 * @param x
			 * @return
			 */
			float transform_x(unsigned int x) const {
				return ((float) x / (float) m_window_width) * m_max_x_coor;
			}

			/**
			 * @brief
			 * @param y
			 * @return
			 */
			unsigned int transform_y(float y) const {
				return static_cast<unsigned int>(y / m_max_y_coor) * m_window_height;
			};

			/**
			 * @brief
			 * @param y
			 * @return
			 */
			float transform_y(unsigned int y) const {
				return ((float) y / (float) m_window_height) * m_max_y_coor;
			}
		private:
			Transformation() = default;

			float m_max_x_coor = 4.0;
			float m_max_y_coor = 3.0;
			unsigned int m_window_width{800};
			unsigned int m_window_height{600};
		};

	}
}

#endif
