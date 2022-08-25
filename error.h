#ifndef _ERROR_H_
#define _ERROR_H_

#include "main.h"
#include "string.h"

void perrorl(const char *msg, ...);
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...);

#endif
