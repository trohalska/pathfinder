#include "libmxpath.h"

int main(int c, char *v[]) {
    // find all errors
    mx_pf_errors(c, v);
    //if (c > 0) printf("%d", mx_strlen(v[0]));
 
    char *str = mx_file_to_str(v[1]);                   //-----create 1
    char **strarr = mx_strsplit(str, '\n');

    int G = mx_atoi(str); // count of islands
    // create line of names
    char **arr_islands = mx_get_arr_islands(G, strarr);    //-----create 2
    // create adj matrix
    int **matrix = mx_get_matrix(G, str, arr_islands);  //-----create 3
    mx_alg_deijkstra(matrix, G, 0);
    

// PRINT-----------------------------
    printf("\n%s\n", "\x1b[32m-------------------INPUT-------------------\033[0m");
    /*printf("%s\n", str);*/
    for (int i = 0; i < G; i++) {
        for (int j = 0; j < G; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("%s", "\n");
    }
    printf("%s\n", "---------------------");
    for (int i = 0; i < G; i++) {
        printf("%d - %s\n", i, arr_islands[i]);
    }
// PRINT-----------------------------
    // printf("\n%s\n", "\x1b[32m----------------CHECKING FOR LEAKS----------------\033[0m");
    
    mx_strdel(&str);                                     //-----d 1
    mx_del_strarr(&strarr);
    mx_strdel(arr_islands);                               //-----d 2
    //mx_del_matrix_int(matrix);                            //  d 3
    
    printf("\n%s\n", "\x1b[32m-------------------LEAKS-------------------\033[0m");
    
    if (*matrix != NULL)
        printf("%s\n", "\x1b[35m matrix \033[0m");
    if (*arr_islands!= NULL)
        printf("%s\n", "\x1b[35m arr_islands \033[0m");
    if (str != NULL)
        printf("%s\n", "\x1b[35m str \033[0m");

    system("leaks -q a");
    return 0;
}

// printf("%s\n", "\x1b[32m--ckeck 6 complete--chech if line is correct\033[0m");
