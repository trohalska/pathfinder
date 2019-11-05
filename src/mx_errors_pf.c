#include "libmxpath.h"

void mx_printerr_line(int i) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(i));
    mx_printerr(" isn't valid\n");
    mx_printerr("for checking islands\n");
    exit(1);
}

void mx_errors_pf(int c, char *v[]) {
//------------------------------------ chech for arguments = 2
    if (c != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    int file = open(v[1], O_RDONLY);

    printf("%s\n", "\x1b[32m--ckeck 1 complete--chech for arguments = 2\033[0m");
//------------------------------------ chech if v[1] exists
    if (file < 0) {            
        mx_printerr("error: file ");
        mx_printerr(v[1]);
        mx_printerr(" doesn't exist\n");
        exit(1);
    }
    printf("%s\n", "\x1b[32m--ckeck 2 complete--chech if v[1] exists\033[0m");
//------------------------------------ chech if v[1] isn't empty
    char buf[1];
    int n = read(file, buf, sizeof(buf));
    if (n <= 0) {
        mx_printerr("error: file ");
        mx_printerr(v[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
    close(file);

    printf("%s\n", "\x1b[32m--ckeck 3 complete--chech if v[1] isn't empty\033[0m");
//------------------------------------ chech if line1 is digit
    char *str = mx_file_to_str(v[1]);
    char **strarr = mx_strsplit(str, '\n');
    free(str); // release str
    str = NULL;

    for (int i = 1; i < mx_strlen(strarr[0]); i++) {
        if (!mx_isdigit(strarr[0][i])) {
            mx_printerr("error: line 1 isn't valid\n");
            exit(1);
        }
    }
    printf("%s\n", "\x1b[32m--ckeck 4 complete--chech if line1 is digit\033[0m");
//------------------------------------ chech if numb of isl is correct
    int countlines = 0;
    for (int i = 0; strarr[i]; i++) {
        countlines++;
    }
    if (mx_atoi(strarr[0]) != countlines - 1) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    printf("%s\n", "\x1b[32m--ckeck 5 complete--chech if numb of isl is correct\033[0m");
//------------------------------------ chech if line is correct
    for (int i = 1; i < countlines; i++) {
        char **p1 = mx_strsplit(strarr[i], '-');
        char **p23 = mx_strsplit(p1[1], ',');
        // check word 1
        for (int j = 1; j < mx_strlen(p1[0]); j++) {
            if (!mx_isalpha(p1[0][j])) {
                mx_printerr_line(i);
            }
        }
        // check word 2
        for (int j = 1; j < mx_strlen(p23[0]); j++) {
            if (p23[0] == '\0' || !mx_isalpha(p23[0][j])) {
                mx_printerr_line(i);
            }
        }
        for (int j = 1; j < mx_strlen(p23[1]); j++) {
            if (!mx_isdigit(p23[1][j])) {
                mx_printerr_line(i);
            }
        }
        mx_del_strarr(&p1);
        mx_del_strarr(&p23);
    }
    printf("%s\n", "\x1b[32m--ckeck 6 complete--chech if line is correct\033[0m");
    mx_del_strarr(&strarr);
}
