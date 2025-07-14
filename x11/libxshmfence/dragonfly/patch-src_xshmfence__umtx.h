--- src/xshmfence_umtx.h.orig	2025-07-14 11:51:30 UTC
+++ src/xshmfence_umtx.h
@@ -0,0 +1,11 @@
+#ifndef _XSHMFENCE_FUTEX_H_
+#define _XSHMFENCE_FUTEX_H_
+
+#include <unistd.h>
+
+struct xshmfence {
+    int     v;
+};
+
+#define xshmfence_init(fd)
+#endif /* _XSHMFENCE_FUTEX_H_ */
