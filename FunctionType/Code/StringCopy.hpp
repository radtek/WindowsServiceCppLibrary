#ifndef __STRINGCOPY_HPP__
#define __STRINGCOPY_HPP__
#include <string.h>

#ifdef UNICODE
#define tcscpy_s wcscpy_s
#else
#define tcscpy_s strcpy_s
#endif
#endif
