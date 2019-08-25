#include "bdd-for-c.h"
#include "cli.h"

spec("CLI") {
	describe("help_text()") {
		it("should return help text") {
			check(strstr(help_text(), "Display this help message."));
		}
	}

	describe("try_text()") {
		it("should return try text") {
			char *try_text_string = "Try \"nw help\" for more info.";
			check(strncmp(try_text("nw"), try_text_string, LINESIZE) == 0);
		}
	}

	describe("usage_text()") {
		it("should return usage text") {
			char *usage_text_string = "USAGE: nw <COMMAND>";
			check(strncmp(usage_text("nw"), usage_text_string, LINESIZE) == 0);
		}
	}
}
