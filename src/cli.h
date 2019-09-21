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

bool match_cmd(char *, const char *);
bool match_help(char *);

char *help_text();
char *try_text(const char *);
char *usage_text(const char *);

void print_help(const char *);
void print_invalid_cmd(const char *, const char *);
void print_no_cmd(const char *);
