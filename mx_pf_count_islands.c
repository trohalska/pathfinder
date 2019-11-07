#include "libmxpath.h"

char **mx_pf_count_islands(int G, char *str)
{   
    for (int i = 1; strarr[i]; i++) {
        char **tmp = mx_pf_split(strarr[i]);


    char **isl_isl_way = mx_strsplit(str, '\n'); //---c-1
    char **arr_is = (char **) malloc((G + 1) * sizeof(char *));
    int i = 0;
    for (; i < G; i++) {
        char **tmp = mx_strsplit(isl_isl_way[i + 1], '-');
        arr_is[i] = mx_strdup(tmp[0]);
        mx_del_strarr(&tmp);
    }    
    arr_is[i] = NULL;
    mx_del_strarr(&isl_isl_way); //---d-1
    return arr_is;
}

