#include "libmxpath.h"

char **mx_pf_split(const char *s) {
    if (!s) return NULL;
    char **res = (char **) malloc((3 + 1) * sizeof(char *));
    
    int n = mx_get_char_index(s, '-');
    res[0] = mx_strndup(s, n);
    s += mx_strlen(res[0]) + 1;

    n = mx_get_char_index(s, ',');
    res[1] = mx_strndup(s, n);
    s += mx_strlen(res[1]) + 1;

    res[2] = mx_strdup(s);
    res[3] = NULL;
    return res;
}
