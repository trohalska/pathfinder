#include "libmxpath.h"

static void print_border();
static void print_path(int i, int startnode, char **arr_islands);
static int *get_route(int i, int *pred, int startnode, int *count);
static void print_route(int i, int *pred, int startnode, char **arr_islands);
static void print_distance(int i, int *distance, int *pred, int startnode);

void mx_print_path(int *distance, int *pred, int g, int startnode, char **arr_islands)
//print the path and distance of each node
{    
	for (int i = 0; i < g; i++) {
		if (i != startnode) {
            print_border();
            print_path(i, startnode, arr_islands);
            print_route(i, pred, startnode, arr_islands);
            print_distance(i, distance);
            print_border();
        }
    }    
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

static void print_route(int i, int *pred, int startnode, char **arr_islands)
{   
    int count = 0;
    int *route = get_route(i, pred, startnode, &count);
    mx_printstr("Route: ");
    for (int i = 0; i <= count; i++) {
        mx_printstr(arr_islands[route[i]]);
        if (i == count) break;
        mx_printstr(" -> ");
    }
    mx_printstr("\n");
    free(route);
    route = NULL;
}

static void print_distance(int i, int *distance, int *pred, int startnode)
{   
    int count = 0;
    int *route = get_route(i, pred, startnode, &count);
    if (count < 3) {
        mx_printstr("Distance: ");
        mx_printint(distance[i]);
        mx_printstr("\n");
    }
    else {}
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
