#include "libmxpath.h"

static t_pred *mx_create_pred(int *p);
static void mx_push_back_pred(t_pred **predstruct, int *pred);
static void fill_all_predstruct (t_pred *predstruct, int i, int nextnode);

t_pred *mx_alg_deijkstra(int **dex, int *distance, int g, int startnode)
{
	int INFINITY = 9999;
	int *pred = malloc (g * sizeof(int));
	t_pred *predstruct = mx_create_pred(pred);
	int visited[g], count, mindistance, nextnode, i;
	
	for (i = 0; i < g; i++) { //initialize pred[], distance[] and visited[]
		distance[i] = dex[startnode][i];
		predstruct->pred[i] = startnode;
		visited[i] = 0;
	}
	
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;	
	while (count < g - 1) {
		mindistance = INFINITY;
		//nextnode gives the node at minimum distance
		for (i = 0; i < g; i++)
			if (distance[i] < mindistance && !visited[i]) {
				mindistance = distance[i];
				nextnode = i;
			}
		//check if a better path exists through nextnode
		visited[nextnode] = 1;
		for (i = 0; i < g; i++)
			if (!visited[i]) {
				if (mindistance + dex[nextnode][i] < distance[i]) {
					distance[i] = mindistance + dex[nextnode][i];
					fill_all_predstruct (predstruct, i, nextnode);					
				}
				if (mindistance + dex[nextnode][i] == distance[i]) {
					int *pred1 = malloc (g * sizeof(int));
					for (int j = 0; j < i; j++) {
						pred1[j] = predstruct->pred[j];
					}
					pred1[i] = nextnode;
					mx_push_back_pred(&predstruct, pred1);
					free(pred1);
					pred1 = NULL;					
				}
			}
		count++;
	}
	return predstruct;
}

static void fill_all_predstruct (t_pred *predstruct, int i, int nextnode) {
	t_pred *p = predstruct;
	p->pred[i] = nextnode;
	while (p->next != NULL) { // find Null-node
		p = p->next;
		p->pred[i] = nextnode;
	}
}

static t_pred *mx_create_pred(int *p)
{
    t_pred *temp;
    if (!p) return NULL;

    temp = malloc(sizeof(t_pred));
    if (!temp) return NULL;

    temp->pred = p;
    temp->next = NULL;
    return temp;
}

static void mx_push_back_pred(t_pred **predstruct, int *pred)
{
    t_pred *tmp;
    t_pred *p;

    if (!predstruct || !pred) return;

    tmp = mx_create_pred(pred); // create new
    if (!tmp) return;

    p = *predstruct;
    if (*predstruct == NULL) { // find Null-node
        *predstruct = tmp;
        return;
    }
    else {
        while (p->next != NULL) // find Null-node
            p = p->next;
        p->next = tmp;
    }
}
