#include "bdd-for-c.h"
#include "cli.h"

spec("cli") {
	describe("try_text()") {
		it("should return try text") {
			char *try_text_string = "Try \"nw help\" for more info.";
			puts(try_text("nw"));
			check(strncmp(try_text("nw"), try_text_string, LINESIZE) == 0);
		}
	}

	describe("usage_text()") {
		it("should return usage text") {
			check(strncmp(usage_text("nw"), "USAGE: nw", LINESIZE) == 0);
		}
	}
}
