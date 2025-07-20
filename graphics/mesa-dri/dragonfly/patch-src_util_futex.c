--- src/util/futex.c.orig	2024-06-06 18:57:27 UTC
+++ src/util/futex.c
@@ -89,6 +89,39 @@ int futex_wait(uint32_t *addr, int32_t v
    return _umtx_op(addr, UMTX_OP_WAIT_UINT, (uint32_t)value, uaddr, uaddr2) == -1 ? errno : 0;
 }
 
+#elif defined(__DragonFly__)
+
+#include <errno.h>
+#include <unistd.h>
+#include <time.h>
+
+int futex_wake(uint32_t *ptr, int count)
+{
+   return umtx_wakeup((volatile const int*)ptr, count);
+}
+
+int futex_wait(uint32_t *ptr, int32_t value, const struct timespec *timeout)
+{
+   int timo = 0;
+   int ret;
+   if (timeout != NULL) {
+      timo = timeout->tv_sec * 1000*1000 + timeout->tv_nsec / 1000; /* XXX check overflow? */
+      if (timo < 0)
+         timo = 1 << 26; /* about 1 minute or so */  // 0x7fffffff; /* XXX ~35 minutes */
+      if (timo == 0 && timeout->tv_nsec > 0)
+         timo = 1; /* cap up to one 1us */
+   }
+   ret = umtx_sleep((volatile const int*)ptr, value, timo);
+   if (ret == 0)
+      return 0;
+   /* errno mangling for compat */
+   if (errno == EBUSY)
+      return EWOULDBLOCK;
+   if (errno == EWOULDBLOCK)
+      return ETIMEDOUT;
+   return errno;
+}
+
 #elif defined(__OpenBSD__)
 
 #include <sys/futex.h>
