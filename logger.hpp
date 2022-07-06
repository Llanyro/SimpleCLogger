/*
 * Logger.hpp
 *
 *  Created on: ??? ?, 2022
 *      Author: llanyro
 */

#ifndef LOGGER_LOGGER_HPP_
#define LOGGER_LOGGER_HPP_

namespace llcpp {
namespace logger {

class Logger {
	protected:
		const char* logger_folder_path;
		unsigned int size;
	private:
		int __custom_log(const char* filename, const unsigned int filename_size, const char* format, void* arg_list) const;
		int __custom_log(const char* filename, const char* format, void* arg_list) const;
	public:
		Logger(const char* logger_folder_path, const unsigned int size);
		Logger(const char* logger_folder_path);
		virtual ~Logger();
		int custom_log(const char* filename, const char* format,...) const;
		int log(const char* format, ...) const;
		int error(const char* format, ...) const;
		int info(const char* format, ...) const;
};

} /* namespace logger */
} /* namespace llcpp */

#endif /* LOGGER_LOGGER_HPP_ */
