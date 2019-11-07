#include "libmxpath.h"

static void mx_printerr_line(int i);

void mx_errors_pf(int c, char *v[]) {
//------------------------------------ chech for arguments = 2
    if (c != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    int file = open(v[1], O_RDONLY);
//------------------------------------ chech if v[1] exists
    if (file < 0) {            
        mx_printerr("error: file ");
        mx_printerr(v[1]);
        mx_printerr(" doesn't exist\n");
        exit(1);
    }
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
//------------------------------------ chech if line is correct
    for (int i = 1; strarr[i]; i++) {
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
    mx_del_strarr(&strarr);
}

static void mx_printerr_line(int i) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(i));
    mx_printerr(" isn't valid\n");
    mx_printerr("for checking islands\n");
    exit(1);
}
