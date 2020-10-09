#ifndef _DXX_UTIL_H_
#define _DXX_UTIL_H_

#if __SAMD51J18A__
#include "d51_util.h"
#elif __SAMD21G18A__
#include "d21_util.h"
#elif __SAMD21E17A__
#include "d21e17_util.h"
#else
#error Please specify a proper header for your processor.
#endif

#if defined(_SAMD51_SERCOM4_INSTANCE_) || defined(_SAMD21_SERCOM4_INSTANCE_)
#define SAMD_SERCOM4_INSTANCE
#endif
#if defined(_SAMD51_SERCOM5_INSTANCE_) || defined(_SAMD21_SERCOM5_INSTANCE_)
#define SAMD_SERCOM5_INSTANCE
#endif

#endif  //_DXX_UTIL_H_
