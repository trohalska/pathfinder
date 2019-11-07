#include "libmxpath.h"

void mx_error_first_line(int c, char *v[]) {
//------------------------------------ chech if numb of isl is correct 
    // int countlines = 0;
    // for (int i = 0; strarr[i]; i++) {
    //     countlines++;
    // }
    if (mx_atoi(strarr[0]) != countlines - 1) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
