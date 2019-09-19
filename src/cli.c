#include "cli.h"

bool match_cmd(char *cmd, const char *cmdtarget) {
	int comparison = strncmp(cmd, cmdtarget, strnlen(cmd, 1000));
	int lengthmatch = (strnlen(cmd, 1000) == strnlen(cmdtarget, 1000));

	if (lengthmatch && (comparison == 0)) return true;
	else return false;
}

bool match_help(char *cmd) {
	return (
		match_cmd(cmd, "-h") || match_cmd(cmd, "--help") ||
		match_cmd(cmd, "h") || match_cmd(cmd, "help")
	);
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

char *try_text(const char *self) {
	const char **strlist = clear_alloc(3, sizeof(strlist));
	*(strlist + 0) = "Try \"";
	*(strlist + 1) = self;
	*(strlist + 2) = " help\" for more info.";

	return assemble_string(3, strlist);
}

char *usage_text(const char *self) {
	const char **strlist = calloc(3, sizeof(strlist));
	*(strlist + 0) = "USAGE: ";
	*(strlist + 1) = self;
	*(strlist + 2) = " <COMMAND>";

	return assemble_string(3, strlist);
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

void print_no_cmd(const char *self) {
	puts(usage_text(self));
	puts(try_text(self));
}
