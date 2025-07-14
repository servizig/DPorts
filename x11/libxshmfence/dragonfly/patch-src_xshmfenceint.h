--- src/xshmfenceint.h.orig	2025-07-14 11:48:28 UTC
+++ src/xshmfenceint.h
@@ -33,7 +33,7 @@
 #endif
 
 #if HAVE_PTHREAD
-#include "xshmfence_pthread.h"
+#include "xshmfence_umtx.h"
 #endif
 
 #endif /* _XSHMFENCEINT_H_ */
