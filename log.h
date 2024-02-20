#ifndef __LOG_H
#define __LOG_H

#include <stdio.h>
#include <stdarg.h>

#define LOG_INFO "\033[1mINFO\033[0m"
#define LOG_WARN "\033[33mWARN\033[0m"
#define LOG_ERROR "\033[31mERROR\033[0m"
#define LOG_FATAL "\033[1;41mFATAL\033[0m"

static inline int __log(const char *logstr, const char *file, const char *func, int line, const char *format, ...) {
	int size = 0;
	va_list args;

	size += printf("[%s] (%s:%d @ %s) ", logstr, file, line, func);

	va_start(args, format);

	size += vprintf(format, args);

	va_end(args);

	return size;
}

#define log(__lvl, ...) \
	__log(__lvl, __FILE__, __func__, __LINE__, __VA_ARGS__)

#endif /* __LOG_H */
