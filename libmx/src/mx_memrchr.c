#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const char *d = s;
    while (n >= 0) {
        n--;
        if (d[n] == c) {
            return (void *)&d[n];
        }
    }
    return NULL;
}
