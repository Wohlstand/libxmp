#include "test.h"

/* These inputs caused hangs in stb_vorbis due to missing EOF checks
 * in start_decoder.
 */

TEST(test_fuzzer_depack_oxm_truncated)
{
	xmp_context opaque;
	int ret;

	opaque = xmp_create_context();
	ret = xmp_load_module(opaque, "data/f/depack_oxm_truncated.oxm");
	fail_unless(ret == -XMP_ERROR_DEPACK, "depacking");

	ret = xmp_load_module(opaque, "data/f/depack_oxm_truncated2.oxm");
	fail_unless(ret == -XMP_ERROR_DEPACK, "depacking");

	xmp_free_context(opaque);
}
END_TEST
