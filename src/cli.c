#include "cli.h"

char *help_text() {
	char *text = (
		"\n"
		"COMMANDS:\n"
		"\n"
		"    h[elp]                  Display this help message.\n"
	);

	return text;
}

char *try_text(const char *self) {
	char *text = calloc(LINESIZE, sizeof(*text));
	strlcpy(text, "Try \"", LINESIZE);
	strlcat(text, self, LINESIZE);
	strlcat(text, " help\" for more info.", LINESIZE);

	return text;
}

char *usage_text(const char *self) {
	char *text = calloc(LINESIZE, sizeof(*text));
	strlcpy(text, "USAGE: ", LINESIZE);
	strlcat(text, self, LINESIZE);
	strlcat(text, " <COMMAND>", LINESIZE);

	return text;
}
