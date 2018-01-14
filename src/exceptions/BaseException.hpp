#pragma once

#include <exception>
#include <string>
#include <stdexcept>

namespace sff {
	namespace error {
		/**
		 * @brief Base exception, all other custom exceptions from it
		 * This makes the usage easier, as there's only one reimplementation of what()
		 * All exceptions are related to file errors (opening, missing info, ...)
		 */
		class BaseException : public std::exception {
		public:
			/**
			 * @brief Constructs a new BaseException
			 * This constructor can be used with a custom reason
			 * @param filename The name of the file that caused the exception
			 * @param reason The reason the exception was caused
			 */
			BaseException(std::string filename, std::string reason)
					: BaseException(filename, reason, "BaseException") {};

			/**
			 * @brief Function that returns the explanation for the exception
			 * @return The explanatory string
			 */
			const char *what() const noexcept override {
				return m_full.c_str();
			}

		protected:
			/**
			 * @brief Constructs a new BaseException
			 * This constructor is the one called by all other exceptions, it correctly sets the exception type
			 * @param filename The name of the file that caused the exception
			 * @param reason The reason the exception was caused
			 * @param type The type of the exception
			 */
			BaseException(std::string filename, std::string reason, std::string type) : std::exception(), m_type(type) {
				m_full = m_type + ": \"" + filename + "\" Reason: \"" + reason + "\"";
			}

			std::string m_full;
			std::string m_type;
		};

		/**
		 * @brief Exception which is caused when the parser is unable to open the file
		 * When seeing this exception the user should check whatever config file
		 * is causing it and make it is properly formatted
		 */
		class ParserOpenException : public BaseException {
		public:
			/**
			 * @brief Constructs a new ParserOpenException
			 * @param filename The name of the file that caused the exception
			 */
			explicit ParserOpenException(std::string filename) : BaseException(filename, "Parser could not open file",
																			   "ParserOpenException") {};
		};

		/**
		 * @brief Exception which is caused when the parser can't find a field
		 * When seeing this exception the user should check whatever config file
		 * is causing it and making sure that the field is defined and has a proper value
		 */
		class ParserFieldException : public BaseException {
		public:
			/**
			 * @brief Constructs a new ParserFieldException
			 * @param filename The name of the file that caused the exception
			 */
			ParserFieldException(std::string filename, std::string field) : BaseException(filename,
																						  "Parser could not find field \"" +
																						  field + "\"",
																						  "ParserFieldException") {};
		};

		/**
		 * @brief Exception which is caused when a file can't be opened
		 * Both SFML files (textures, fonts, ...) and fstream files
		 * should throw this exception if they're unable to open their files
		 */
		class FileOpenException : public BaseException {
		public:
			/**
			 * @brief Constructs a new FileOpenException
			 * @param filename The name of the file that caused the exception
			 */
			explicit FileOpenException(std::string filename) : BaseException(filename, "Could not open file",
																			 "FileOpenExciption") {};
		};
	}
}
