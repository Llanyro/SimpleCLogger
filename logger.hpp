/*
 * Logger.hpp
 *
 *  Created on: ??? ?, 2022
 *      Author: llanyro
 */

#ifndef LOGGER_LOGGER_HPP_
#define LOGGER_LOGGER_HPP_

#include "llcppheaders/llanytypeslib.hpp"

namespace llcpp {
namespace logger {

class Logger {
	protected:
		const char* logger_folder_path;
		len_t size;
	private:
		int __custom_log(const char* filename, const len_t filename_size, const char* format, void* arg_list) const;
		int __custom_log(const char* filename, const char* format, void* arg_list) const;
	public:
		Logger(const char* logger_folder_path, const len_t size);
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
