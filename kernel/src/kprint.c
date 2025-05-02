#include "kprint.h"

#include <stdarg.h>

#define BUF_SIZE 128

#if defined(NDEBUG) || !defined(VERBOSITY)
#undef VERBOSITY
#define VERBOSITY 0
#endif

extern void kputc(char c);

void kputs(const char *s)
{
	while (*s != '\0') {
		kputc(*s++);
	}
}

void kprintf(const char *restrict fmt, ...)
{
	kputs(fmt);
}
