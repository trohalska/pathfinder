#include "libmx.h"

void mx_del_matrix_int(int **str) {
	if (*str && str) {
		free(*str);
		*str = NULL;
	}
}

// void mx_del_matrix_int(int **str) {
// 	int i = 0;
// 	if (str[i] != NULL) {
// 		free(str[i]);
// 		str[i] = NULL;
// 	}
// 	free(str);
// 	str = NULL;
// }

// void mx_del_matrix_int(int **str) {
// 	for (int i = 0; str[i] && malloc_size(str[i]); i++) {			
// 		free(str[i]);
// 		str = NULL;
// 	} 
// }

// void mx_del_matrix_int(int **str) {
// 	int **p = str;
// 	while (*p) {
// 		free(*p);
// 		*p = NULL;
// 		(*p)++;
// 	}
// 	free(p);
// 	str = NULL;
// }
