#include "libmxpath.h"

static int **create_matrix(int G);

int **mx_get_matrix(int G, char *str)
{
    printf("%s\n", str);
    
    char **arr_is = mx_get_arr_islands(G, str);
    int **matrix = create_matrix(G);

    for (int i = 0; i < G; i++) {
        char **tmp_isl_1 = mx_strsplit(isl_isl_way[i + 1], '-');
        char **tmp_isl_2_3 = mx_strsplit(tmp_isl_1[1], ',');
        // check word 1
        for (int j = 0; j < G; j++) {
            if (mx_strcmp(arr_is[i], tmp_isl_1[0]) == 0 
                && mx_strcmp(arr_is[j], tmp_isl_2_3[0]) == 0) {
                matrix[i][j] = mx_atoi(tmp_isl_2_3[1]);
            }
            else if (mx_strcmp(arr_is[i], tmp_isl_2_3[0]) == 0 
                && mx_strcmp(arr_is[j], tmp_isl_1[0]) == 0) {
                matrix[j][i] = mx_atoi(tmp_isl_2_3[1]);
            }
            // else matrix[j][i] = 0;
        }
        mx_del_strarr(&tmp_isl_1);
        mx_del_strarr(&tmp_isl_2_3);
    }
    
    mx_del_strarr(&arr_is);
    printf("%s\n", "\x1b[32m--ckeck complete--\033[0m");
    return matrix;    
}

static int **create_matrix(int G) // picture to matrix
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

