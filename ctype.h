#ifndef _CTYPE_H_
#define _CTYPE_H_

#include "main.h"

bool isalnumchar(int c);
bool isalphachar(int c);
bool isdigitchar(int c);
bool isidentchar(int c);
bool isspacechar(int c);
bool isquotechar(int c);
bool isnumberchar(const char *s);

#endif
