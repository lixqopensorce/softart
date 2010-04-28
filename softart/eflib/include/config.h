#ifndef EFLIB_CONFIG_H
#define EFLIB_CONFIG_H

#include "user_config.h"
#include <boost/config.hpp>

#if defined(DEBUG) | defined(_DEBUG)
#	define EFLIB_DEBUG
#endif

#ifdef BOOST_MSVC
#	define EFLIB_MSVC
#	define EFILB_COMPILE_VER _MSC_VER
#	ifdef _UNICODE
#		define EFLIB_UNICODE
#	endif

#	if _MSC_VER >= 1600
#	elif _MSC_VER >= 1500
#		ifndef EFLIB_DEBUG
#			define _SECURE_SCL 0
#		endif
#	elif _MSC_VER >= 1400
#		ifndef EFLIB_DEBUG
#			define _SECURE_SCL 0
#		endif
#	endif

#	if _MSC_VER >= 1400
#		pragma warning(disable: 4251 4275 4819)
#		ifndef _CRT_SECURE_NO_DEPRECATE
#			define _CRT_SECURE_NO_DEPRECATE
#		endif
#		ifndef _SCL_SECURE_NO_DEPRECATE
#			define _SCL_SECURE_NO_DEPRECATE
#		endif
#	endif

#endif

#ifdef BOOST_WINDOWS
#	define EFLIB_WINDOWS
#endif

#ifdef EFLIB_WINDOWS
#	ifndef BOOST_ALL_DYN_LINK
#		define BOOST_ALL_DYN_LINK
#	endif
#endif

#ifndef EFLIB_DEBUG
#	ifndef SOFTART_MULTITHEADING_ENABLED
#		define SOFTART_MULTITHEADING_ENABLED
#	endif
#endif

#endif
