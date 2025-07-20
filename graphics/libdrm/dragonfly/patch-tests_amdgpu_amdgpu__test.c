--- tests/amdgpu/amdgpu_test.c.orig	2025-06-19 13:10:30 UTC
+++ tests/amdgpu/amdgpu_test.c
@@ -39,7 +39,7 @@
 #include <stdint.h>
 #ifdef __linux__
 #include <linux/limits.h>
-#elif __FreeBSD__
+#elif __DragonFly__
 /* SPECNAMELEN in FreeBSD is defined here: */
 #include <sys/param.h>
 #endif
@@ -640,7 +640,7 @@ static bool amdgpu_node_is_drm(int maj, int min)
      * only device nodes in /dev/dri/ */
     return (!strncmp(name, "drm/", 4) || !strncmp(name, "dri/", 4));
 #else
-    return maj == DRM_MAJOR;
+    return true;
 #endif
 }
 
