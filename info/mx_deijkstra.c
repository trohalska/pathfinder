#include "libmxpath.h"

void mx_alg_deijkstra(int **dex, int *distance, int *pred1, int g, int startnode)
{
	int INFINITY = 9999;
	int visited[g], count, mindistance, nextnode, i, pred[g];
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far	
	
	//initialize pred[], distance[] and visited[]
	for (i = 0; i < g; i++) {
		distance[i] = dex[startnode][i];
		pred[i] = startnode;
		pred1[i] = startnode;
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
					pred[i] = nextnode;
					pred1[i] = nextnode;
				}
				if (mindistance + dex[nextnode][i] == distance[i]) {
					pred1[i] = nextnode;
				}
			}
		count++;
	}
}
