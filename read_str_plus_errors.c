#include "libmxpath.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || !delim) return;
    while(*arr) {
        mx_printstr(*arr);
        if (*(arr + 1) == NULL) break;
        mx_printstr(delim);
        arr++;
    }
    mx_printstr("\n");
}

int **read_str_plus_errors(char *str, int *){
    *h = get_h(v);
    *w = get_w(v);
    char buf = 'a';
    int fd = open(v, O_RDONLY);
    int n = read(fd, &buf, 1);

    char **str = (char **) malloc(*h * sizeof(char *));

    for (int i = 0; i < *h && n > 0; i++) {
        char *s = malloc(*w * sizeof(char));

        for (int j = 0; j < *w && n > 0 && buf != '\n'; j++) {
            s[j] = buf;
            n = read(fd, &buf, sizeof(buf));
        }
        str[i] = s;
        n = read(fd, &buf, sizeof(buf));
    }
    return str;
}
