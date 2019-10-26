#ifndef QPORTKNOCKING_GLOBAL_H
#define QPORTKNOCKING_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPORTKNOCKING_LIBRARY)
#  define QPORTKNOCKINGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPORTKNOCKINGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPORTKNOCKING_GLOBAL_H