#include "libmx.h"

int main(int c, char *v[]) 
{
    mx_pf_errors(c, v); // find all errors
    char *str = mx_file_to_str(v[1]);
    char **strarr = mx_strsplit(str, '\n');
    int G = mx_atoi(str); // count of islands
    // create line of names & check for line1
    char **arr_islands = mx_get_arr_islands(G, strarr);
    int **matrix = mx_get_matrix(G, str, arr_islands); // create adj matrix
    int **dex = mx_create_dex_matrix(matrix, G); // create dex matrix
    t_all_paths *paths = mx_get_all_paths(dex, G); // get linled list of paths
    mx_printpaths(paths, matrix, arr_islands); // print paths

    mx_strdel(&str); // clean all created
    mx_del_strarr(&strarr);
    mx_strdel(arr_islands);
    mx_del_matrix_int(matrix);
    mx_del_matrix_int(dex);

    return 0;
}
