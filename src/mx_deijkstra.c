#include "libmxpath.h"

// int main()
// {
// 	int G[MAX][MAX],i,j,n,u;
// 	printf("Enter no. of vertices:");
// 	scanf("%d",&n);
// 	printf("\nEnter the adjacency matrix:\n");
	
// 	for(i=0;i<n;i++)
// 		for(j=0;j<n;j++)
// 			scanf("%d",&G[i][j]);
	
// 	printf("\nEnter the starting node:");
// 	scanf("%d",&u);
// 	dijkstra(G,n,u);
	
// 	return 0;
// }
 
void mx_alg_deijkstra(int **matrix, int g, int startnode)
{
	int INFINITY = 9999;
	int dex[g][g], distance[g], pred[g];
	int visited[g], count, mindistance, nextnode, i, j;
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far

	//create the dex matrix
	for (i = 0; i < g; i++)
		for (j = 0; j < g; j++)
			if (matrix[i][j] == 0)
				dex[i][j] = INFINITY;
			else
				dex[i][j] = matrix[i][j];
	
	//initialize pred[], distance[] and visited[]
	for (i = 0; i < g; i++) {
		distance[i] = dex[startnode][i];
		pred[i] = startnode;
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
				if (!visited[i])
					if (mindistance + dex[nextnode][i] < distance[i]) {
						distance[i] = mindistance + dex[nextnode][i];
						pred[i] = nextnode;
					}
		count++;
	}

	//print the path and distance of each node
	
	for (i = 0; i < g; i++)
		if (i != startnode) {
			printf("\nDistance of node%d = %d", i, distance[i]);
			printf("\nPath = %d",i);
			j = i;
			//mx_str_reverse((char *)pred);
			// while (j != startnode){
			// 	j = pred[j];
			// 	mx_printstr("<->");
			// 	mx_printint(pred[j]);
			// }

			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);

			//mx_printstr("\n");
	}

	int k = 0;
	//mx_printstr("\n\n");
	while (k != g){
		printf("%d ", pred[k]);
		k++;
	}
}
