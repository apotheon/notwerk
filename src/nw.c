#include "cli.h"

int main(int argc, char **argv) {
	const char *program = *(argv);

	if (argc > 1) {
		char *cmd = *(argv + 1);

		if (match_cmd(cmd, "help")) print_help(program);
		else printf("invalid command: %s\n", cmd);
	} else {
		puts(usage_text(program));
		puts(try_text(program));
	}

	return 0;
}
