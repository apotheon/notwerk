#include "bdd-for-c.h"
#include "cli.h"

spec("CLI") {
	describe("match_cmd()") {
		const char *target_string = "help";
		int cmdsize = sizeof(target_string);

		it("should return true with a command match") {
			char *cmd = calloc(strlen(target_string), cmdsize);

			strlcpy(cmd, target_string, cmdsize);
			check(match_cmd(cmd, target_string) == true);
		}

		it("should return false with a command mismatch") {
			char *cmd = "help-me";
			check(match_cmd(cmd, target_string) == false);
		}
	}

	describe("match_help()") {
		it("should return false with incorrect help command") {
			check(match_help("help-me") == false);
		}

		it("should return false with incorrect help option") {
			check(match_help("--help-me") == false);
		}

		it("should return false with non-help command") {
			check(match_help("start") == false);
		}

		it("should return true with correct help commands") {
			check(match_help("h") && match_help("help"));
		}

		it("should return true with correct help options") {
			check(match_help("-h") && match_help("--help"));
		}

		it("should return false with partial help command") {
			check(match_help("--he") == false)
		}
	}

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
