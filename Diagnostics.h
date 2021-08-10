#ifndef EMBEDDED_DIAGNOSTICS_H
#define EMBEDDED_DIAGNOSTICS_H

#define TRACE_ENABLED

#ifdef TRACE_ENABLED
#include <Arduino.h>
// use __FUNCTION__ or __func__ instead to reduce
// memory consumption by cutting off member's signature
#define traceme trace(__PRETTY_FUNCTION__);

inline void trace(const char c[])
{
    Serial.println(c);
}
#else
#define traceme
#endif // end of TRACE_ENABLED
#endif // end of EMBEDDED_DIAGNOSTICS_H
