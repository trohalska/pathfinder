#include "libmx.h"

static void get_word(int *i, char **arr_is, char *tmp);

char **mx_get_arr_islands(int G, char **strarr){   
    int i = 0;
    char **arr_is = (char **) malloc((G + 1) * sizeof(char *));

    for (int j = 1; strarr[j] ; j++) {
        char **tmp = mx_pf_split(strarr[j]);
        get_word(&i, arr_is, tmp[0]);
        get_word(&i, arr_is, tmp[1]);
        mx_del_strarr(&tmp);
    }
    if (i != G) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    arr_is[i] = NULL;
    return arr_is;
}

static void get_word(int *i, char **arr_is, char *tmp) {
    int flag = 0;
    for (int k = 0; arr_is[k] && k < *i; k++) {
        if (mx_strcmp(arr_is[k], tmp) == 0){
            flag += 1;
        }
    }
    if (flag == 0) {
        arr_is[*i] = mx_strdup(tmp);
        *i += 1;
    }
}

