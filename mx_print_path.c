#include "libmxpath.h"

static void print_border();
static void print_path(int i, int startnode, char **arr_islands);
static int *get_route(int i, int *pred, int startnode, int *count);
static void print_route(int *count, int *route, char **arr_islands);
static void print_distance(int i, int *count, int *route, int *distance, int **matrix);

void mx_print_path(int *distance, int *pred, int i, int startnode, char **arr_islands, int **matrix)
//print the path and distance of each node
{   	
    print_border();
    print_path(i, startnode, arr_islands);

    int count = 0;
    int *route = get_route(i, pred, startnode, &count);
    
    // printf("count %d = %d\n", i, count);
    // for (int i = 0; i <= count; i++) {
    //     printf("%d -> ", route[i]);
    // }
    // mx_printstr("\n");
    
    print_route(&count, route, arr_islands);
    print_distance(i, &count, route, distance, matrix);
    print_border();

    free(route);
    route = NULL;
}

static void print_border()
{
    for (int k = 0; k < 40; k++)
        mx_printchar('=');
    mx_printstr("\n");
}

static void print_path(int i, int startnode, char **arr_islands)
{
    mx_printstr("Path: ");
    mx_printstr(arr_islands[startnode]);
    mx_printstr(" -> ");
    mx_printstr(arr_islands[i]);
    mx_printstr("\n");
}

static int *get_route(int i, int *pred, int startnode, int *count)
{
    int j = i, k = 0;
    while (j != startnode) {
        j = pred[j];
        k++;
    }
    j = i;
    *count = k;
    int *route = malloc(k * sizeof(int));
    route[k] = i;
    while (j != startnode && k > 0) {
        j = pred[j];
        k--;
        route[k] = j;
    }
    return route;
}

static void print_route(int *count, int *route, char **arr_islands)
{   
    mx_printstr("Route: ");
    for (int i = 0; i <= *count; i++) {
        mx_printstr(arr_islands[route[i]]);
        if (i == *count) break;
        mx_printstr(" -> ");
    }
    mx_printstr("\n");
    
}

static void print_distance(int i, int *count, int *route, int *distance, int **matrix)
{   
    int j = 1;
    mx_printstr("Distance: ");
    if (*count > 1) {
        while (j <= *count) {
            mx_printint(matrix[route[j - 1]][route[j]]);
            if ((j + 1) > *count) break;
            mx_printstr(" + ");
            j++;
        }
         mx_printstr(" = ");
    }
    mx_printint(distance[i]);
    mx_printstr("\n");
}
