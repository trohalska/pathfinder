#include "libmx.h"

int **mx_get_matrix(int G, char *str, char **arr_islands)
{
    int **matrix = mx_create_matrix(G, 0); //--------------- c-2
    char **strarr = mx_strsplit(str, '\n'); //--------------- c-3
    
    for (int i = 0; strarr[i]; i++) {
        int mi = 0;
        int mj = 0;
        char **tmp = mx_pf_split(strarr[i]); //--------------- c-4
        for (int j = 0; j < G; j++) {
            if (mx_strcmp(arr_islands[j], tmp[0]) == 0) {
                mi = j;
            }
            if (mx_strcmp(arr_islands[j], tmp[1]) == 0) {
                mj = j;
            }
        }
        matrix[mi][mj] = mx_atoi(tmp[2]);
        matrix[mj][mi] = mx_atoi(tmp[2]);
        mx_del_strarr(&tmp); //--------------- d-4
    }
    mx_del_strarr(&strarr);//--------------- d-3
    return matrix;//--------------- r-2
}
