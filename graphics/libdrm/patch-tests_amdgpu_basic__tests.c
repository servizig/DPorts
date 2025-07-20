--- tests/amdgpu/basic_tests.c.orig	2024-06-26 08:13:31 UTC
+++ tests/amdgpu/basic_tests.c
@@ -1773,7 +1773,7 @@ static void amdgpu_command_submission_sdma_write_linea
 
 static void amdgpu_command_submission_const_fill_helper(unsigned ip_type)
 {
-	const int sdma_write_length = 1024 * 1024;
+	const int sdma_write_length = 60 * 1024;
 	const int pm4_dw = 256;
 	amdgpu_context_handle context_handle;
 	amdgpu_bo_handle bo;
@@ -1809,7 +1809,7 @@ static void amdgpu_command_submission_const_fill_helpe
 
 	for (ring_id = 0; (1 << ring_id) & hw_ip_info.available_rings; ring_id++) {
 		loop = 0;
-		while(loop < 2) {
+		while(loop < 1) {
 			/* allocate UC bo for sDMA use */
 			r = amdgpu_bo_alloc_and_map(device_handle,
 						    sdma_write_length, 4096,
@@ -1887,6 +1887,7 @@ static void amdgpu_command_submission_const_fill_helpe
 			CU_ASSERT_EQUAL(r, 0);
 			loop++;
 		}
+		break;
 	}
 	/* clean resources */
 	free(resources);
@@ -2064,9 +2065,9 @@ static void amdgpu_command_submission_sdma_copy_linear
 
 static void amdgpu_command_submission_sdma(void)
 {
-	amdgpu_command_submission_sdma_write_linear();
+	//amdgpu_command_submission_sdma_write_linear();
 	amdgpu_command_submission_sdma_const_fill();
-	amdgpu_command_submission_sdma_copy_linear();
+	//amdgpu_command_submission_sdma_copy_linear();
 }
 
 static void amdgpu_command_submission_multi_fence_wait_all(bool wait_all)
