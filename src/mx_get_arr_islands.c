#include "libmxpath.h"

char **mx_get_arr_islands(int G, char *str)
{   
    char **isl_isl_way = mx_strsplit(str, '\n');
    
    for (int i = 0; i <= G; i++) {
        printf("- %s\n", isl_isl_way[i]);
    }

    char **arr_is = (char **) malloc((G + 1) * sizeof(char *));
    int i = 0;
    for (; i < G; i++) {
        char **tmp = mx_strsplit(isl_isl_way[i + 1], '-');
        arr_is[i] = mx_strdup(tmp[0]);
        mx_del_strarr(&tmp);
    }    
    arr_is[i] = NULL;
    mx_del_strarr(&isl_isl_way);
    return arr_is;
}
