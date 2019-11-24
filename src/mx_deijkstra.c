#include "libmxpath.h"

int **mx_alg_deijkstra(int **dex, int *distance, int g, int startnode)
{
	int INFINITY = 9999;
	int visited[g], count, mindistance, nextnode, i;

	int **pred = malloc (3 * sizeof(int *));
	int *tmp = malloc (sizeof(int));
	int *tmp1 = malloc (sizeof(int));
	pred[0] = tmp;
	pred[1] = tmp1;
	pred[2] = NULL;	
	
	//initialize pred[], distance[] and visited[]
	for (i = 0; i < g; i++) {
		distance[i] = dex[startnode][i];
		// for (int j = 0; pred[j]; j++) {
		// 	pred[j][i] = startnode;
		// }
		pred[0][i] = startnode;
		pred[1][i] = startnode;
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
