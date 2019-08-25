#include "bdd-for-c.h"
#include "util.h"

spec("Util") {
	describe("strlist_size()") {
		it("should return 200 for space filled with 5 4-char strings") {
			char **strlist = calloc(5 * 5, sizeof(char));

			for (int i = 0; i < 5; ++i) *(strlist + i) = "abcd";

			check(strlist_size(5, strlist) == 200);
		}

	}
}
