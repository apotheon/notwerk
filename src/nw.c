#include "cli.h"

int main(int argc, char **argv) {
	const char *program = *(argv);

	if (argc == 1) {
		puts(usage_text(program));
		puts(try_text(program));
	} else if (argc == 2) {
		char *cmd = *(argv + 1);

		if (match_cmd(cmd, "help")) {
			puts("");
			puts(usage_text(program));
			puts(help_text());
		}
	}

	return 0;
}
