--- src/util/u_process.c.orig	2024-06-06 18:57:27 UTC
+++ src/util/u_process.c
@@ -231,7 +231,7 @@ util_get_process_exec_path(char* process
    int result = _NSGetExecutablePath(process_path, &bufSize);
 
    return (result == 0) ? strlen(process_path) : 0;
-#elif DETECT_OS_FREEBSD
+#elif DETECT_OS_FREEBSD || DETECT_OS_DRAGONFLY
    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
 
    (void) sysctl(mib, 4, process_path, &len, NULL, 0);
