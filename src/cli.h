#ifndef NW_H_
#define NW_H_

#define LINESIZE 1000

#include <libgen.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

#endif

bool match_cmd(char *cmd, const char *cmdtarget);

char *assemble_string(const char **strlist);
char *help_text();
char *try_text(const char *self);
char *usage_text(const char *self);

void print_help(const char *self);
void print_invalid_cmd(const char *self, const char *cmd);
