#include "util.h"

size_t strlist_size(uint64_t n, const char **stringlist) {
	size_t total = 0;

	for (uint64_t i = 0;  i < n; ++i) {
		size_t typesize = sizeof(*(stringlist + 1));
		size_t stringlength = (strlen(*(stringlist + 1)) + 1);
		total += typesize * stringlength;
	}

	return total;
}
