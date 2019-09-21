#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *assemble_string(uint16_t, const char **);

size_t strlist_size(uint64_t, const char **);

void *clear_alloc(size_t, size_t);
