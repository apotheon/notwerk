#include "cli.h"

bool match_cmd(char *cmd, const char *cmdtarget) {
	if (strncmp(cmd, cmdtarget, strnlen(cmd, LINESIZE)) == 0) return true;
	else return false;
}

char *help_text() {
	char *text = (
		"\n"
		"COMMANDS:\n"
		"\n"
		"    h[elp]                  Display this help message.\n"
	);

	return text;
}

char *assemble_string(const char **strlist) {
	size_t listsize = strlist_size(3, strlist);
	char *text = calloc(listsize, sizeof(text));

	size_t remaining_length = listsize;

	for (int i = 0; i < 3; ++i) {
		strlcat(text, *(strlist + i), remaining_length);
		remaining_length -= strlen(*(strlist + i));
	}

	return text;
}

char *try_text(const char *self) {
	const char **strlist = calloc(3, sizeof(strlist));
	*(strlist + 0) = "Try \"";
	*(strlist + 1) = self;
	*(strlist + 2) = " help\" for more info.";

	return assemble_string(strlist);
}

char *usage_text(const char *self) {
	const char **strlist = calloc(3, sizeof(strlist));
	*(strlist + 0) = "USAGE: ";
	*(strlist + 1) = self;
	*(strlist + 2) = " <COMMAND>";

	return assemble_string(strlist);
}

void print_help(const char *self) {
	puts("");
	puts(usage_text(self));
	puts(help_text());
}

void print_invalid_cmd(const char *self, const char *cmd) {
	printf("invalid command: %s\n", cmd);
	puts(try_text(self));
}
