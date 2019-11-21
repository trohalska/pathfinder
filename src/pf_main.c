#include "libmxpath.h"

int main(int c, char *v[]) 
{
    mx_pf_errors(c, v); // find all errors

    //if (c > 0) printf("%d", mx_strlen(v[0]));

    char *str = mx_file_to_str(v[1]);
    char **strarr = mx_strsplit(str, '\n');

    int G = mx_atoi(str); // count of islands
    char **arr_islands = mx_get_arr_islands(G, strarr); // create line of names
    int **matrix = mx_get_matrix(G, str, arr_islands); // create adj matrix
    int **dex = mx_create_dex_matrix(matrix, G); // create dex matrix

    int *distance = malloc (G * sizeof(int));
    int *pred = malloc (G * sizeof(int));

    int startnode = 0;
    mx_alg_deijkstra(dex, distance, pred, G, startnode);
    mx_print_path(distance, pred, G, startnode, arr_islands);

    mx_printstr("\n\n");
    int k = 0;
	for (k = 0; k != G; k++){
		printf("%d ", pred[k]);
	}	
	for (k = 0; k != G; k++){
		printf("%d ", distance[k]);
	}





// -------------------INPUT-------------------
    printf("\n%s\n", "\x1b[32m-------------------INPUT-------------------\033[0m");
    /*printf("%s\n", str);*/
    for (int i = 0; i < G; i++) {
        for (int j = 0; j < G; j++) {
            if (matrix[i][j] == 0)
                printf("%s\t", "-");
            else
                printf("%d\t", dex[i][j]);
        }
        printf("%s", "\n");
    }
    printf("%s\n", "---------------------");
    for (int i = 0; i < G; i++) {
        printf("%d - %s\n", i, arr_islands[i]);
    }
//-------------------INPUT-------------------

    mx_strdel(&str);
    mx_del_strarr(&strarr);
    mx_strdel(arr_islands);
    mx_del_matrix_int(matrix);
    mx_del_matrix_int(dex);
    //mx_strdel(distance);
    //mx_strdel(pred);
    

    // printf("%s\n", "\x1b[32m-------------------LEAKS-------------------\033[0m");
    
    // if (*matrix != NULL)
    //     printf("%s\n", "\x1b[35m matrix \033[0m");
    // if (*arr_islands!= NULL)
    //     printf("%s\n", "\x1b[35m arr_islands \033[0m");
    // if (str != NULL)
    //     printf("%s\n", "\x1b[35m str \033[0m");
    // system("leaks -q a");

    return 0;
}

// printf("%s\n", "\x1b[32m--ckeck 6 complete--chech if line is correct\033[0m");
