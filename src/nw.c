#include <libgen.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	const char *program = *(argv);
	printf("USAGE: %s\n", basename(strndup(program, PATH_MAX)));

	return 0;
}
