/*
 * Logger.cpp
 *
 *  Created on: ??? ?, 2022
 *      Author: llanyro
 */

#include "logger.hpp"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#if defined(_WIN32)
#include <direct.h>
#include <stdlib.h>

#include <assert.h>

#include <io.h>

#pragma warning( disable:4996)
#elif defined(__unix__)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif


#define LOG "log.log"
#define ERROR "error.log"
#define INFO "info.log"

namespace llcpp {
namespace logger {
int Logger::__custom_log(const char* filename, const len_t filename_size, const char* format, void* arg_list) const {
	int done = 0;

	len_t size = filename_size + this->size + 2;
	char* path = new char[size];

	// Concat strings
	memcpy(path, this->logger_folder_path, this->size);
	path[this->size] = '/';
	memcpy(path + this->size + 1, filename, filename_size);
	path[size - 1] = '\0';

	FILE* f = fopen(path, "a+");
	va_list arg = (va_list)arg_list;

	#if defined(_WIN32)
	done = vfprintf(f, format, arg);
	#elif defined(__unix__)
	done = __vfprintf_internal(f, format, arg, 0);
	#endif

	if (done > 0) {
		putc('\n', f);
		done++;
	}

	fclose(f);

	va_end(arg);
	delete[] path;
	return done;
}
int Logger::__custom_log(const char* filename, const char* format, void* arg_list) const {
	return this->__custom_log(filename, strlen(filename), format, arg_list);
}

Logger::Logger(const char* logger_folder_path, const len_t size) {
	this->logger_folder_path = logger_folder_path;
	this->size = size;

	if (_access(this->logger_folder_path, 0) != 0) {
		#if defined(_WIN32)
		_mkdir(this->logger_folder_path);
		#elif defined(__unix__)
		mkdir(this->logger_folder_path, 0700);
		#endif
	}
}
Logger::Logger(const char* logger_folder_path) : Logger(logger_folder_path, strlen(logger_folder_path)) {}
Logger::~Logger() {}
int Logger::custom_log(const char* filename, const char* format, ...) const {
	int done;
	va_list arg;
	va_start(arg, format);
	done = this->__custom_log(filename, format, arg);
	return done;
}
int Logger::log(const char* format, ...) const {
	int done;
	va_list arg;
	va_start(arg, format);
	done = this->__custom_log(LOG, sizeof(LOG), format, arg);
	return done;
}
int Logger::error(const char* format, ...) const {
	int done;
	va_list arg;
	va_start(arg, format);
	done = this->__custom_log(ERROR, sizeof(ERROR), format, arg);
	return done;
}
int Logger::info(const char* format, ...) const {
	int done;
	va_list arg;
	va_start(arg, format);
	done = this->__custom_log(INFO, sizeof(INFO), format, arg);
	return done;
}

} /* namespace logger */
} /* namespace llcpp */