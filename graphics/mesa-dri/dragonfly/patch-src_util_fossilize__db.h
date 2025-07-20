--- src/util/fossilize_db.h.orig	Sun May 11 11:15:02 2025
+++ src/util/fossilize_db.h	Sun May
@@ -37,10 +37,6 @@
 #define FOZ_DB_UTIL 1
 #endif
 
-#ifdef HAVE_SYS_INOTIFY_H
-#define FOZ_DB_UTIL_DYNAMIC_LIST 1
-#endif
-
 #include <stdbool.h>
 #include <stdint.h>
 #include <stdio.h>
