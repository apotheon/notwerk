#include <libgen.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	const char *program = *(argv);
	printf("USAGE: %s\n", basename(strdup(program)));

	return 0;
}
