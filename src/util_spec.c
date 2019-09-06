#include "bdd-for-c.h"
#include "util.h"

spec("Util") {
	describe("assemble_string()") {
		it("should assemble one string from three strings") {
			const char *target_string = "foobarbaz";

			const char **strlist = calloc(3, sizeof(strlist));
			*(strlist + 0) = "foo";
			*(strlist + 1) = "bar";
			*(strlist + 2) = "baz";

			check(strstr(assemble_string(3, strlist), target_string));
		}
	}

	describe("strlist_size()") {
		it("should return 200 for 5 4-char strings") {
			const char **strlist = calloc(5 * 5, sizeof(strlist));
			for (int i = 0; i < 5; ++i) *(strlist + i) = "abcd";
			check(strlist_size(5, strlist) == 200);
		}

		it("should return 160 for 5 3-char strings") {
			const char **strlist = calloc(5 * 5, sizeof(strlist));
			for (int i = 0; i < 5; ++i) *(strlist + i) = "abc";
			check(strlist_size(5, strlist) == 160);
		}

	}
}
