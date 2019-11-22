#include "libmxpath.h"

static int *get_route(int i, int *pred, int startnode, int *count);
static t_all_paths *mx_create_path(int c, int *route, int *d);
static void mx_push_back_path(t_all_paths **paths, int c, int *route, int *d);

t_all_paths *mx_get_all_paths(int **matrix, int G)
{
    int *distance;
    int *pred;
    t_all_paths *paths = NULL;
    int **dex = mx_create_dex_matrix(matrix, G); // create dex matrix

    for (int startnode = 0; startnode < G - 1; startnode++) {

        distance = malloc (G * sizeof(int));
        pred = malloc (G * sizeof(int));

        mx_alg_deijkstra(dex, distance, pred, G, startnode);
        for (int i = startnode + 1; i < G; i++) {
            if (i != startnode) {
                int count = 0;
                int *route = get_route(i, pred, startnode, &count);
                mx_push_back_path(&paths, count, route, &distance[i]);            
            }
        }

                    
                    int k = 0;
                    for (k = 0; k != G; k++){
                        mx_printstr(" ");
                        mx_printint(pred[k]);
                    }

                    mx_printstr("\n");
                    for (k = 0; k != G; k++){
                        mx_printstr(" ");
                        mx_printint(distance[k]);
                    }
                    mx_printstr("\n---\n");

        free(distance);
        free(pred);        
    }
    return paths;
}

static int *get_route(int i, int *pred, int startnode, int *count)
{
    int j = i;
    int k = 0;

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

static t_all_paths *mx_create_path(int c, int *route, int *d)
{
    t_all_paths *temp;

    if (!c || !route || !d) return NULL;

    temp = malloc(sizeof(t_all_paths));
    if (!temp) return NULL;

    temp->number = 0;
    temp->count = c;
    temp->path = route;
    temp->distance = *d;
    temp->next = NULL;
    return temp;
}

static void mx_push_back_path(t_all_paths **paths, int c, int *route, int *d)
{
    t_all_paths *tmp;
    t_all_paths *p;

    if (!paths || !c || !route || !d) return;

    tmp = mx_create_path(c, route, d); // create new
    if (!tmp) return;

    p = *paths;
    if (*paths == NULL) { // find Null-node
        *paths = tmp;
        return;
    }
    else {
        while (p->next != NULL) // find Null-node
            p = p->next;
        p->next = tmp;
    }
}
