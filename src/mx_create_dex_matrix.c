#include "libmxpath.h"

int **mx_create_dex_matrix(int **matrix, int g) 
{
	int INFINITY = 9999;
    int **dex = mx_create_matrix(g, INFINITY);
	for (int i = 0; i < g; i++)
		for (int j = 0; j < g; j++)
			if (matrix[i][j] != 0)
				dex[i][j] = matrix[i][j];
    return dex;
}

