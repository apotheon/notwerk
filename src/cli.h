#ifndef NW_H_
#define NW_H_

#define LINESIZE 1000

#include <libgen.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#endif

bool match_cmd(char *cmd, char *cmdtarget);

char *help_text();
char *try_text(const char *self);
char *usage_text(const char *self);
