#include "util.h"

char *assemble_string(uint16_t listlen, const char **strlist) {
	size_t listsize = strlist_size(listlen, strlist);
	char *text = calloc(listsize, sizeof(text));

	size_t remaining_length = listsize;

	for (int i = 0; i < listlen; ++i) {
		strlcat(text, *(strlist + i), remaining_length);
		remaining_length -= strlen(*(strlist + i));
	}

	return text;
}

size_t strlist_size(uint64_t n, const char **stringlist) {
	size_t total = 0;

	for (uint64_t i = 0;  i < n; ++i) {
		size_t typesize = sizeof(*(stringlist + 1));
		size_t stringlength = (strlen(*(stringlist + 1)) + 1);
		total += typesize * stringlength;
	}

	return total;
}
