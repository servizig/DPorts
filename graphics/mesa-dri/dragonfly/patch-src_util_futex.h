--- src/util/futex.h.orig	2024-06-06 18:57:27 UTC
+++ src/util/futex.h
@@ -28,6 +28,8 @@
 #define UTIL_FUTEX_SUPPORTED 1
 #elif defined(__FreeBSD__)
 #define UTIL_FUTEX_SUPPORTED 1
+#elif defined(__DragonFly__)
+#define UTIL_FUTEX_SUPPORTED 1
 #elif defined(__OpenBSD__)
 #define UTIL_FUTEX_SUPPORTED 1
 #elif defined(_WIN32) && !defined(WINDOWS_NO_FUTEX)
