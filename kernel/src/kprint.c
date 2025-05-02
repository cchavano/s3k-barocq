#include "kprint.h"

#include <stdarg.h>

#define BUF_SIZE 128

#if defined(NDEBUG) || !defined(VERBOSITY)
#undef VERBOSITY
#define VERBOSITY 0
#endif

void _kputc(char c) __attribute__((weak));

void _kputc(char)
{
}

static void _kputs(const char *s)
{
	while (*s != '\0') {
		_kputc(*s++);
	}
}

void kputs(unsigned int level, const char *s)
{

	if (level > VERBOSITY)
		return;
	_kputs(s);
}

void kprintf(unsigned int level, const char *restrict fmt, ...)
{
	/* TODO PRINTF */
	kputs(level, fmt);
}
