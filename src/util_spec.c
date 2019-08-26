#include "bdd-for-c.h"
#include "util.h"

spec("Util") {
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
