#include "libmxpath.h"

char **mx_get_arr_islands(int G, char *str)
{   
    char **strarr = mx_strsplit(str, '\n');
  
    char **arr_is = (char **) malloc((G + 1) * sizeof(char *));
    int i = 0;
    char *str2 = mx_strdup(str);
    for (int j = 1; strarr[j]; j++) {
        char **tmp = mx_pf_split(strarr[j]);
        if (mx_count_substr(str2, tmp[0]) > 0) {
            arr_is[i] = mx_strdup(tmp[0]);
            i++;
            str2 = mx_replace_substr(str2, tmp[0], " ");
        }
        if (mx_count_substr(str2, tmp[1]) > 0) {
            arr_is[i] = mx_strdup(tmp[1]);
            i++;
            str2 = mx_replace_substr(str2, tmp[1], " ");
        }
        mx_del_strarr(&tmp);
    }

    // int i = 0;
    // for (; i < G; i++) {
    //     char **tmp = mx_pf_split(strarr[j]);
    //     int flag = 0;
    //     for (int j = 0; j < G && arr_is[j]; j++) {
    //         if (mx_strcmp(tmp[0], arr_is[j])) == 0)
    //         flag = -1;
    //     }
    //     if (flag = 0) {
    //         arr_is[i] = mx_strdup(tmp[0]);
    //         i++;
    //     }
    //     else flag = 0;
    //     for (int j = 0; j < G && arr_is[j]; j++) {
    //         if (mx_strcmp(tmp[1], arr_is[j])) == 0)
    //         flag = -1;
    //     }
    //     if (flag = 0) {
    //         arr_is[i] = mx_strdup(tmp[1]);
    //         i++;
    //     }
    //     else flag = 0;
    //     mx_del_strarr(&tmp);
    // }    
    arr_is[i] = NULL;
    mx_del_strarr(&strarr);
    return arr_is;
}
