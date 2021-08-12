# embedded-diagnostics

Simple tracing capabilities: just copy the file to your project and include in every file where you want to use tracing, then put `traceme` wherever you want to write to serial the func/ctor/etc. name along with signature. When your sketch is ready for production, just comment out `TRACE_ENABLED` flag to disable tracing. When it's disabled, it does cost nothing for your flash and RAM!
