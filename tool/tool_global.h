#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TOOL_LIB)
#  define TOOL_EXPORT Q_DECL_EXPORT
# else
#  define TOOL_EXPORT Q_DECL_IMPORT
# endif
#else
# define TOOL_EXPORT
#endif
