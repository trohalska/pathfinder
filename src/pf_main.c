#include "libmxpath.h"

int visited[10];    //n is no of vertices and graph is sorted in array G[10][10]   
    int i,j;

void DFS(int i)
{
    int j;
	printf("\n%d", i);
    visited[i] = 1;
	
	for (j = 0; j < 10; j++)
       if (!visited[j] && matrix[i][j] != 0)
            DFS(j);
}

int main(int c, char *v[]) {
    mx_pf_errors(c, v);
    char *str = mx_file_to_str(v[1]);                   //-----create 1
    int G = mx_atoi(str); // count of islands
    char **arr_islands = mx_get_arr_islands(G, str);    //-----create 2
    int **matrix = mx_get_matrix(G, str, arr_islands);  //-----create 3  
    
    //visited is initialized to zero
    for(i = 0; i < G; i++)
        visited[i] = 0;

    DFS(0);

// PRINT-----------------------------
    printf("%s\n", str);
    printf("%s\n", "---------------------");
    for (int i = 0; i < G; i++) {
        for (int j = 0; j < G; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("%s", "\n");
    }
    printf("G = %d\n", G);
    printf("%s\n", "---------------------");
    for (int i = 0; i < G; i++) {
        printf("- %s\n", arr_islands[i]);
    }
    for (int i = 0; i < G; i++) {
        printf("- %s\n", arr_islands[i]);
    }
// PRINT-----------------------------
    mx_strdel(&str);                                     //-----d 1
    return 0;
}

// printf("%s\n", "\x1b[32m--ckeck 6 complete--chech if line is correct\033[0m");
    
    
//     if (c != 3) {
// 		mx_printerr("usage: ./mx_cp [source_file] [target_file]\n");
// 		exit (1);
//         return 0;
// 	}
//     //check is crs or drt exist
// 	int src = open(v[1], O_RDONLY);
//     if (src < 0) {    
//         mx_printerr("mx_cp: ");
//         mx_printerr(v[1]);
//         mx_printerr(": ");
//         mx_printerr(strerror(errno));
//         mx_printerr("\n");
//         exit(1);
//         return 0;
//     }    
//     int dst = open(v[2], O_WRONLY);
//     //if dst exists - exit
//     if (dst > 0) {
//         exit(1);
//         return 0;
//     }
//     //if dst didn't exists - create
//     if (dst < 0) {
//         dst = open(v[2], O_WRONLY | O_CREAT);
//     }
//     // src to dst
//     char buf[1];
//     int n = read(src, buf, 1);
//     while (n > 0) {
//         write(dst, buf, n);
//         n = read(src, buf, 1);
//     }
// 	close(src);
//     close(dst);    
// 	return 0;
// }
