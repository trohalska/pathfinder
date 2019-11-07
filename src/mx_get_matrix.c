#include "libmxpath.h"

static int **create_matrix(int G);

int **mx_get_matrix(int G, char *str)
{
    char **arr_is = mx_get_arr_islands(G, str);//--------------- c-1
    int **matrix = create_matrix(G); //--------------- c-2
    char **isl_isl_way = mx_strsplit(str, '\n'); //--------------- c-3

    for (int i = 0; i < G; i++) {
        char **tmp_isl_1 = mx_strsplit(isl_isl_way[i + 1], '-'); //--------------- c-4
        char **tmp_isl_2_3 = mx_strsplit(tmp_isl_1[1], ',');//--------------- c-5
        for (int j = 0; j < G; j++) {
            if (mx_strcmp(arr_is[i], tmp_isl_1[0]) == 0 
                && mx_strcmp(arr_is[j], tmp_isl_2_3[0]) == 0) {
                matrix[i][j] = mx_atoi(tmp_isl_2_3[1]);
                matrix[j][i] = mx_atoi(tmp_isl_2_3[1]);
            }
        }
        mx_del_strarr(&tmp_isl_1); //--------------- d-4
        mx_del_strarr(&tmp_isl_2_3);//--------------- d-5
    }
    mx_del_strarr(&arr_is);//--------------- d-1
    mx_del_strarr(&isl_isl_way);//--------------- d-3
    return matrix;//--------------- r-2
}

static int **create_matrix(int G) // 0-matrix
{
    int **str = (int **) malloc(G * sizeof(int *));
    for (int i = 0; i < G; i++) {
        int *s = malloc(G * sizeof(int));
        for (int j = 0; j < G; j++) {
            s[j] = 0;
        }
        str[i] = s;
    }
    return str;
}

