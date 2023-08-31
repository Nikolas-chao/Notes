#ifndef SYS_LOG_H
#define SYS_LOG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

void printf_log(const char *file, const char *func, const int line);

#endif