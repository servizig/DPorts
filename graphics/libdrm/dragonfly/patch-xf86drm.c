--- xf86drm.c.orig	2024-06-26 08:13:31 UTC
+++ xf86drm.c
@@ -62,7 +62,7 @@
 #endif
 #include <inttypes.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/param.h>
 #include <sys/pciio.h>
 #endif
@@ -3342,6 +3342,8 @@ static bool drmNodeIsDRM(int maj, int min)
      * in /dev/drm/ and links in /dev/dri while a WIP in kernel driver creates
      * only device nodes in /dev/dri/ */
     return (!strncmp(name, "drm/", 4) || !strncmp(name, "dri/", 4));
+#elif defined(__DragonFly__)
+    return true;	/* DragonFly BSD has no fixed major device numbers */
 #else
     return maj == DRM_MAJOR;
 #endif
@@ -3455,7 +3457,7 @@ static char *drmGetMinorNameForFD(int fd, int type)
 
     closedir(sysdir);
     return NULL;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
     struct stat sbuf;
     char dname[SPECNAMELEN];
     const char *mname;
