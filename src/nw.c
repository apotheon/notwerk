#include "cli.h"

int main(int argc, char **argv) {
	const char *program = *(argv);
	puts(usage_text(program));
	puts(try_text(program));

	return 0;
}
