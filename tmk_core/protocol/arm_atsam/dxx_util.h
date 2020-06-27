#ifndef _DXX_UTIL_H_
#define _DXX_UTIL_H_

#if __SAMD51J18A__
#include "d51_util.h"
#elif __SAMD21G18A__
#include "d21_util.h"
#else
#error Please specify a proper header for your processor.
#endif

#endif  //_DXX_UTIL_H_
