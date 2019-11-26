#include "libmx.h"

static int *get_route(int i, int *pred, int startnode, int *count);
static t_all_paths *mx_create_path(int c, int *route, int *d);
static void mx_push_back_path(t_all_paths **paths, int c, int *route, int *d);
static bool compare_arr_int(int count1, int count2, int *arr1, int *arr2);

t_all_paths *mx_get_all_paths(int **dex, int G)
{
    t_all_paths *paths = NULL;
    for (int startnode = 0; startnode < G - 1; startnode++) {
        int *distance = malloc (G * sizeof(int));
        int **pred = mx_alg_deijkstra(dex, distance, G, startnode);
        bool flag = compare_arr_int(G, G, pred[0], pred[1]);
        // поиск всех путей от начальной точки до заданной 
        for (int i = startnode + 1; i < G; i++) {
            //if (i != startnode) {
                int count0 = 0;        
                int *route0 = get_route(i, pred[0], startnode, &count0);
                if (!flag) {
                    int count1 = 0;
                    int *route1 = get_route(i, pred[1], startnode, &count1);
                    if (!compare_arr_int(count0, count1, route0, route1))
                        mx_push_back_path(&paths, count1, route1, &distance[i]);
                    else free(route1);
                }
                mx_push_back_path(&paths, count0, route0, &distance[i]);
            //}
        }
        mx_del_arr_matrix_int(&pred);
        free(distance);
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
    *count = k + 1;
    int *route = malloc((k + 1) * sizeof(int));
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

static bool compare_arr_int(int count1, int count2, int *arr1, int *arr2) 
{
    if (!arr1 || !arr2) return false;
    if (count1 == count2) {
        for (int i = 0; arr1[i] == arr2[i]; i++) {
            if (i == count1 - 1) {
                return true;
            }
        }
    }
    return false;
}
