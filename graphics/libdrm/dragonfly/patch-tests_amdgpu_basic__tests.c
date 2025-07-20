--- tests/amdgpu/basic_tests.c.orig	2024-06-26 08:13:31 UTC
+++ tests/amdgpu/basic_tests.c
@@ -1879,7 +1879,10 @@ static void amdgpu_command_submission_const_fill_helpe
 			/* verify if SDMA test result meets with expected */
 			i = 0;
 			while(i < (sdma_write_length / 4)) {
-				CU_ASSERT_EQUAL(bo_cpu[i++], 0xdeadbeaf);
+				CU_ASSERT_EQUAL(bo_cpu[i], 0xdeadbeaf);
+				if (bo_cpu[i] != 0xdeadbeaf)
+					printf("CU_ASSERT_EQUAL: %d == 0x%x\n", i, bo_cpu[i]);
+				i++;
 			}
 
 			r = amdgpu_bo_unmap_and_free(bo, va_handle, bo_mc,
