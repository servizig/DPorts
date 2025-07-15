--- src/xshmfence_umtx.c.orig	2025-07-14 12:22:29 UTC
+++ src/xshmfence_umtx.c
@@ -0,0 +1,61 @@
+#if HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+#include <errno.h>
+
+#include "xshmfenceint.h"
+
+#define barrier() __asm__ __volatile__("": : :"memory")
+
+static inline void atomic_store(int32_t *f, int32_t v)
+{
+	barrier();
+	*f = v;
+	barrier();
+}
+
+static inline int32_t atomic_fetch(int32_t *a)
+{
+	int32_t v;
+	barrier();
+	v = *a;
+	barrier();
+	return v;
+}
+
+int
+xshmfence_trigger(struct xshmfence *f)
+{
+	if (__sync_val_compare_and_swap(&f->v, 0, 1) == -1) {
+		atomic_store(&f->v, 1);
+		if (umtx_wakeup(&f->v, 0) < 0)
+			return -1;
+	}
+	return 0;
+}
+
+int
+xshmfence_await(struct xshmfence *f)
+{
+	while (__sync_val_compare_and_swap(&f->v, 0, -1) != 1) {
+		if (umtx_sleep(&f->v, -1, 0)) {
+			if (errno != EINVAL)
+				return -1;
+		}
+	}
+
+	return 0;
+}
+
+int
+xshmfence_query(struct xshmfence *f)
+{
+	return atomic_fetch(&f->v) == 1;
+}
+
+void
+xshmfence_reset(struct xshmfence *f)
+{
+	__sync_bool_compare_and_swap(&f->v, 1, 0);
+}
