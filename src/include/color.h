#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

// Color Definitions
// COLOR_RESET  "\033[0m"
// BOLD         "\033[1m"
// BLACK_TEXT   "\033[30;1m"
// RED_TEXT     "\033[31;1m"
// GREEN_TEXT   "\033[32;1m"
// YELLOW_TEXT  "\033[33;1m"
// BLUE_TEXT    "\033[34;1m"
// MAGENTA_TEXT "\033[35;1m"
// CYAN_TEXT    "\033[36;1m"
// WHITE_TEXT   "\033[37;1m"
// End Color Definitions

enum Colors {
	BOLD,
	BLACK_TEXT,
	RED_TEXT,
	GREEN_TEXT,
	YELLOW_TEXT,
	BLUE_TEXT,
	MAGENTA_TEXT,
	CYAN_TEXT,
	WHITE_TEXT
};

void colored_printer(FILE *stream, enum Colors color, const char *fmt, ...) {
	va_list vaList;
	assert(stream!=NULL);

	if (!isatty(fileno(stream)))
    {
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        return;
    }

    // Print to console with color:
    switch (color)
    {
    case RED_TEXT :
        fprintf(stream, "\033[31;1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;

    case BOLD:
        fprintf(stream, "\033[1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;

    case BLACK_TEXT:
        fprintf(stream, "\033[30;1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;

    case GREEN_TEXT:
        fprintf(stream, "\033[32;1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;

    case YELLOW_TEXT:
	    fprintf(stream, "\033[33;1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;

	case BLUE_TEXT:
        fprintf(stream, "\033[34;1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;

	case MAGENTA_TEXT:
        fprintf(stream, "\033[35;1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;

	case CYAN_TEXT:
        fprintf(stream, "\033[36;1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;

	case WHITE_TEXT:
        fprintf(stream, "\033[37;1m");
        va_start(vaList, fmt);
        vfprintf(stream, fmt, vaList);
        va_end(vaList);
        fprintf(stream, "\033[0m");
        break;
    }
}

#endif