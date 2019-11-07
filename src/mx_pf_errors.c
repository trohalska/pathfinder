#include "libmxpath.h"

static void mx_printerr_line(int i);

void mx_pf_errors(int c, char *v[]) {
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

    for (int i = 1; i < mx_strlen(strarr[0]); i++) {
        if (!mx_isdigit(strarr[0][i])) {
            mx_printerr("error: line 1 isn't valid\n");
            exit(1);
        }
    }
//------------------------------------ chech if line is correct '-' ','
    for (int i = 1; strarr[i]; i++) {
        int count_space = 0;
        int count_comma = 0;
        int get_char = 0;
        for (int j = 0; strarr[i][j] && count_space < 2; j++) {
            get_char = mx_get_char_index(&strarr[i][j], '-');
            if (get_char != -1) {
                count_space += 1;
                j += get_char;
            }
            else break;
        }
        for (int j = 0; strarr[i][j] && count_comma < 2; j++) {
            get_char = mx_get_char_index(&strarr[i][j], ',');
            if (get_char != -1) {
                count_comma += 1;
                j += get_char;
            }
            else break;
        }
        if (count_comma != 1 || count_space != 1) {
            mx_printerr_line(i);
            exit(1);
        }
    }
//------------------------------------ chech if line is correct digits
    for (int i = 1; strarr[i]; i++) {
        char **tmp = mx_pf_split(strarr[i]);
        for (int j = 0; j < mx_strlen(tmp[0]); j++) {
            if (!mx_isalpha(tmp[0][j])) {
                mx_printerr_line(i);
            }
        }
        for (int j = 0; j < mx_strlen(tmp[1]); j++) {
            if (!mx_isalpha(tmp[1][j])) {
                mx_printerr_line(i);
            }
        }
        for (int j = 0; j < mx_strlen(tmp[2]); j++) {
            if (!mx_isdigit(tmp[2][j])) {
                mx_printerr_line(i);
            }
        }
        mx_del_strarr(&tmp);
    }
//------------------------------------ chech if numb of isl is correct
    int G1 = mx_atoi(str);
    int G = 0;
    char *str1 = mx_strdup(str);
    for (int j = 1; strarr[j]; j++) {
        char **tmp = mx_pf_split(strarr[j]);
        if (mx_count_substr(str1, tmp[0]) > 0) {
            G += 1;
            str1 = mx_replace_substr(str1, tmp[0], " ");
        }
        if (mx_count_substr(str1, tmp[1]) > 0) {
            G += 1;
            str1 = mx_replace_substr(str1, tmp[1], " ");
        }
        mx_del_strarr(&tmp);
    }
    mx_strdel(&str1);
    
    if (G != G1) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }

    mx_strdel(&str);
    mx_del_strarr(&strarr);
}

static void mx_printerr_line(int i) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(i + 1));
    mx_printerr(" isn't valid\n");
    exit(1);
}
