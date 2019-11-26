#include "libmx.h"

static int **initialize_pred(int g, int startnode);
static void initialize_visited(int *visited, int g, int startnode);
static void initialize_distance(int *distance, int g, int startnode, int **dex);

int **mx_alg_deijkstra(int **dex, int *distance, int g, int startnode)
{
	int INFINITY = 999999;
	int visited[g], count, mindistance, nextnode, i;
	int **pred = initialize_pred(g, startnode);
	initialize_visited(visited, g, startnode);
	initialize_distance(distance, g, startnode, dex);
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
					pred[0][i] = nextnode;
					pred[1][i] = nextnode;
				}
				if (mindistance + dex[nextnode][i] == distance[i]) {
					pred[1][i] = nextnode;
				}
			}
		count++;
	}
	return pred;
}

static int **initialize_pred(int g, int startnode)
{
	int **pred = malloc (3 * sizeof(int *));
	pred[0] = malloc(g * sizeof(int));
	pred[1] = malloc(g * sizeof(int));
	pred[2] = NULL;

	for (int i = 0; i < g; i++) {
		pred[0][i] = startnode;
		pred[1][i] = startnode;
	}
	return pred;
}

static void initialize_visited(int *visited, int g, int startnode)
{
	for (int i = 0; i < g; i++) {
		visited[i] = 0;
	}
	visited[startnode] = 1;
}

static void initialize_distance(int *distance, int g, int startnode, int **dex)
{
	for (int i = 0; i < g; i++) {
		distance[i] = dex[startnode][i];
	}
	distance[startnode] = 0;
}
