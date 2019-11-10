#include "libmxpath.h"

char **mx_get_arr_islands(int G, char **strarr)
{   
    char **arr_is = (char **) malloc((G + 1) * sizeof(char *));
    int i = 0;
    int flag0 = 0;
    int flag1 = 0;

    for (int j = 1; strarr[j] ; j++) {
        flag0 = 0;
        flag1 = 0;
        char **tmp = mx_pf_split(strarr[j]);
        for (int k = 0; arr_is[k] && k < i; k++) {
            if (mx_strcmp(arr_is[k], tmp[0]) == 0){
                flag0 += 1;
            }
            if (mx_strcmp(arr_is[k], tmp[1]) == 0){
                flag1 += 1;
            }
        }
        if (flag0 == 0) {
            arr_is[i] = mx_strdup(tmp[0]);
            i++;
        }
        if (flag1 == 0) {
            arr_is[i] = mx_strdup(tmp[1]);
            i++;
        }
        mx_del_strarr(&tmp);
    }
    if (i != G) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    arr_is[i] = NULL;
    return arr_is;
}
