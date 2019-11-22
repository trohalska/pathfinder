#ifndef LIBMXPATH_H
#define LIBMXPATH_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>
//#include "libmx/inc/libmx.h"
#include "../libmx/inc/libmx.h"
//#include <string.h>

// typedef struct s_alist_node {
//     int dest;
//     struct s_alist_node *next;
// } t_alist_node;

// typedef struct s_alist {
//     struct s_alist_onenode *head;
// } t_alist;

int **mx_create_matrix(int G, int fillin);
void mx_del_arr_matrix_int(int ***arr);
void mx_del_matrix_int(int **str);

//----- local specific functions only for pathfinder

typedef struct s_all_paths {
    int number;
    int count;
    int* path;
    int distance;
    struct s_all_paths *next;
} t_all_paths;

void mx_pf_errors(int c, char *v[]);
char **mx_get_arr_islands(int G, char **strarr);
int **mx_get_matrix(int G, char *str, char **arr_islands);
char **mx_pf_split(const char *s);
int **mx_create_dex_matrix(int **matrix, int g);
void mx_alg_deijkstra(int **dex, int *distance, int *pred, int g, int startnode);
t_all_paths *mx_get_all_paths(int **matrix, int G);
void mx_printpaths(t_all_paths *paths, int **matrix, char **arr_islands);

#endif
