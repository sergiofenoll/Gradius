#pragma once

#include <exception>
#include <string>
#include <stdexcept>

namespace sff {
	namespace error {
		/**
		 * @brief
		 */
		class FileException : public std::exception {
		public:
			explicit FileException(std::string filename) : std::exception(), m_filename(filename) {};
			virtual const char *what() const noexcept override {
				std::string s = "An exception occured when handling the file: \"" + m_filename + "\".";
				 return s.c_str();
			}
		protected:
			std::string m_filename;
		};

		class ConfigFileException : public FileException {
		public:
			explicit ConfigFileException(std::string filename, std::string field = {}) : FileException(filename), m_field(field) {};
			virtual  const char *what() const noexcept override {
				std::string s = "An exception occured when handling the config file: \"" + m_filename + "\".\n";
				if (m_field.empty()) s += "It might be badly formatted.";
				else s += "Check the field: \"" + m_field + "\" .";
				return s.c_str();
			}
		private:
			std::string m_field;
		};

		class MediaFileException : public FileException {
		public:
			explicit MediaFileException(std::string filename) : FileException(filename) {};
			virtual const char *what() const noexcept override {
				std::string s = "An exception occured when handling the media file: \"" + m_filename + "\".";
				return s.c_str();
			}
		};
	}
}
