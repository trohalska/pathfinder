#include "libmxpath.h"

static int *get_route(int i, t_pred *predstruct, int startnode, int *count);
static t_all_paths *mx_create_path(int c, int *route, int *d);
static void mx_push_back_path(t_all_paths **paths, int c, int *route, int *d);

void mx_printpred(t_pred *list, int g) {
    t_pred *q = list;
    while (q != NULL) {  
		for (int i = 0; i < g; i++){
			mx_printint(q->pred[i]);
			mx_printstr(" ");
		}  
        mx_printstr("\n");
        q = q->next;
    }
	if (q == NULL)
		mx_printstr("NULL\n");
}
 

t_all_paths *mx_get_all_paths(int **matrix, int G)
{
    int *distance;
    t_pred *predstruct;
    t_all_paths *paths = NULL;
    int **dex = mx_create_dex_matrix(matrix, G); // create dex matrix

    for (int startnode = 0; startnode < G - 1; startnode++) {

        distance = malloc (G * sizeof(int));
        predstruct = mx_alg_deijkstra(dex, distance, G, startnode);

        mx_printpred(predstruct, G);
        
        for (int i = startnode + 1; i < G; i++) {
            if (i != startnode) {
                int count = 0;
                //predstruct = predstruct->next;
                int *route = get_route(i, predstruct, startnode, &count);
                mx_push_back_path(&paths, count, route, &distance[i]);

                
            }
        }

                    mx_printstr("\n");
                    for (int k = 0; k != G; k++){
                        mx_printstr(" ");
                        mx_printint(distance[k]);
                    }
                    mx_printstr("\n---\n");
                    

        free(distance);
        //free(pred);        
    }
    return paths;
}

static int *get_route(int i, t_pred *predstruct, int startnode, int *count)
{
    int j = i;
    int k = 0;

    while (j != startnode) {
        j = predstruct->pred[j];
        k++;
    }
    j = i;
    *count = k;
    int *route = malloc(k * sizeof(int));
    route[k] = i;
    while (j != startnode && k > 0) {
        j = predstruct->pred[j];
        k--;
        route[k] = j;
    }

    // for (int i = 0; i < *count; i++) {
    //     mx_printint(route[i]);

    // }
    // mx_printstr("\n");

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
