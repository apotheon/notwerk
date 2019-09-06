#include "cli.h"

int main(int argc, char **argv) {
	const char *program = *(argv);

	if (argc > 1) {
		char *cmd = *(argv + 1);

		if (match_help(cmd)) print_help(program);
		else print_invalid_cmd(program, cmd);
	} else {
		print_no_cmd(program);
	}

	return 0;
}
