#include "bdd-for-c.h"
#include "cli.h"

spec("notwerk") {
	describe("usage_text()") {
		it("should return usage text") {
			check(strncmp(usage_text("nw"), "USAGE: nw", LINESIZE) == 0);
		}
	}
}
