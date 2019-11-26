#include "libmx.h"

static void print_border();
static void print_path(t_all_paths *paths, char **arr_islands);
static void print_route(t_all_paths *paths, char **arr_islands);
static void print_distance(t_all_paths *paths, int **matrix);

void mx_printpaths(t_all_paths *paths, int **matrix, char **arr_islands)
{ //print the path and distance of each node
    t_all_paths *q = paths;

    if (paths != NULL) {
        for (; q != NULL; q = q->next) {
            print_border();
            print_path(q, arr_islands);
            print_route(q, arr_islands);
            print_distance(q, matrix);
            print_border();
        }
    }
    else {
        mx_printstr("paths == 0 (NULL)\n");
    }
}

static void print_border()
{
    for (int k = 0; k < 40; k++)
        mx_printchar('=');
    mx_printstr("\n");
}

static void print_path(t_all_paths *paths, char **arr_islands) 
{
    mx_printstr("Path: ");
    mx_printstr(arr_islands[paths->path[0]]);
    mx_printstr(" -> ");
    mx_printstr(arr_islands[paths->path[paths->count - 1]]);
    mx_printstr("\n");
}

static void print_route(t_all_paths *paths, char **arr_islands)
{   
    mx_printstr("Route: ");
    for (int i = 0; i < paths->count; i++) {
        mx_printstr(arr_islands[paths->path[i]]);
        if (i == paths->count - 1) break;
        mx_printstr(" -> ");
    }
    mx_printstr("\n");
}

static void print_distance(t_all_paths *paths, int **matrix)
{   
    int j = 1;
    mx_printstr("Distance: ");
    if (paths->count > 2) {
        while (j < paths->count) {
            mx_printint(matrix[paths->path[j - 1]][paths->path[j]]);
            if (j == paths->count - 1) break;
            mx_printstr(" + ");
            j++;
        }
         mx_printstr(" = ");
    }
    mx_printint(paths->distance);
    mx_printstr("\n");
}
