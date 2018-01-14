#pragma once

#include <SFML/Graphics.hpp>
#include "Singleton.hpp"

namespace sff {
	namespace utils {
		/**
		 * @brief POD struct
		 * Holds coordinates in pixels
		 */
		struct PixelPosition {
			/**
			 * @brief Constructs a PixelPosition
			 * @param x The x position
			 * @param y The y position
			 */
			explicit PixelPosition(unsigned int x, unsigned int y) : x(x), y(y) {};
			unsigned int x;
			unsigned int y;
		};

		/**
		 * @brief POD struct
		 * Holds coordinates in game coordinates
		 */
		struct CoordPosition {
			/**
			 * @brief Constructs a CoordPosition
			 * @param x The x position
			 * @param y The y position
			 */
			explicit CoordPosition(float x, float y) : x(x), y(y) {};
			float x;
			float y;
		};

		/**
		 * @brief An implementation of Transformation
		 * Transforms pixel coordinates into game coordinates and vice versa
 		 */
		class Transformation : public Singleton<Transformation> {
		public:
			friend class Singleton<Transformation>;

			/**
			 * @brief Internally saves the window resolution
			 * @param width The window width
			 * @param height The window height
			 */
			void set_resolution(unsigned int width, unsigned int height) {
				m_window_width = width;
				m_window_height = height;
			}

			/**
			 * @brief Transforms a game coordinates into pixel coordinates
			 * @param coords The game coordinates
			 * @return The transformed pixel coordinates
			 */
			PixelPosition transform(CoordPosition coords) const {
				auto x_pix = static_cast<unsigned int>((coords.x / m_max_x_coor) * m_window_width);
				auto y_pix = static_cast<unsigned int>((coords.y / m_max_y_coor) * m_window_height);
				return PixelPosition(x_pix, y_pix);
			};

			/**
			 * @brief Transforms pixel coordinates into game coordinates
			 * @param pixels The pixel coordinates
			 * @return The transformed game coordinates
			 */
			CoordPosition transform(PixelPosition pixels) const {
				auto x_coord = ((float) pixels.x / (float) m_window_width) * m_max_x_coor;
				auto y_coord = ((float) pixels.y / (float) m_window_height) * m_max_y_coor;
				return CoordPosition(x_coord, y_coord);
			};

			/**
			 * @brief Transform a game x position into a pixel x position
			 * @param x The game x position
			 * @return The transformed pixel x position
			 */
			unsigned int transform_x(float x) const {
				return static_cast<unsigned int>(x / m_max_x_coor) * m_window_width;
			};

			/**
			 * @brief Transforms a pixel x position into a game x position
			 * @param x The pixel x position
			 * @return The transformed game x positon
			 */
			float transform_x(unsigned int x) const {
				return ((float) x / (float) m_window_width) * m_max_x_coor;
			}

			/**
			 * @brief Transform a game y position into a pixel y position
			 * @param y The game y position
			 * @return The transformed pixel y position
			 */
			unsigned int transform_y(float y) const {
				return static_cast<unsigned int>(y / m_max_y_coor) * m_window_height;
			};

			/**
			 * @brief Transforms a pixel y position into a game y position
			 * @param y The pixel y position
			 * @return The transformed game y positon
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
