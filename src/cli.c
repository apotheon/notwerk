#include "cli.h"

char *usage_text(const char *self) {
	char *text = calloc(LINESIZE, sizeof(*text));
	strlcpy(text, "USAGE: ", LINESIZE);
	strlcat(text, self, LINESIZE);

	return text;
}