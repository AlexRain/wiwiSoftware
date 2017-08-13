#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(COMMUNICATION_LIB)
#  define COMMUNICATION_EXPORT Q_DECL_EXPORT
# else
#  define COMMUNICATION_EXPORT Q_DECL_IMPORT
# endif
#else
# define COMMUNICATION_EXPORT
#endif
