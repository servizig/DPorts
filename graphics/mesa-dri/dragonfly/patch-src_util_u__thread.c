--- src/util/u_thread.c.orig	2024-09-30 16:28:05 UTC
+++ src/util/u_thread.c
@@ -84,7 +84,7 @@ void u_thread_setname( const char *name
       buf[len] = '\0';
       pthread_setname_np(pthread_self(), buf);
    }
-#elif DETECT_OS_FREEBSD || DETECT_OS_OPENBSD
+#elif DETECT_OS_FREEBSD || DETECT_OS_OPENBSD || DETECT_OS_DRAGONFLY
    pthread_set_name_np(pthread_self(), name);
 #elif DETECT_OS_NETBSD
    pthread_setname_np(pthread_self(), "%s", (void *)name);
