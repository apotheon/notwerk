#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *assemble_string(uint16_t listlen, const char **strlist);

size_t strlist_size(uint64_t n, const char **stringlist);

void *clear_alloc(size_t datalength, size_t datasize);
