#ifndef LIBA_STRINGS_H
#define LIBA_STRINGS_H

#if (_PRIZM)

#include <stdlib.h>

#include "../private/macros.h"

LIBA_BEGIN_DECLS

void bzero(void * s, size_t n);

LIBA_END_DECLS

#else

#include_next <strings.h>

#endif

#endif