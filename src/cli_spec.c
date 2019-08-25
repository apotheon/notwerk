#include "bdd-for-c.h"
#include "cli.h"

spec("cli") {
	describe("usage_text()") {
		it("should return usage text") {
			check(strncmp(usage_text("nw"), "USAGE: nw", LINESIZE) == 0);
		}
	}
}
