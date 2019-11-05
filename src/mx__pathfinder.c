#include "libmxpath.h"

int main(int c, char *v[]) {
    mx_errors_pf(c, v);
    // if (c != 2) {
    //     mx_printstr("ckeck errors unavaliable");
    // }

    char *str = mx_file_to_str(v[1]);
    char **strarr = mx_strsplit(str, '\n');
    free(str); 
    str = NULL;
    int G = mx_atoi(strarr[0]);

    printf("G = %d\n", G);
    for (int i = 1; i < G; i++) {
        printf("- %s\n", strarr[i]);
    }

    return 0;
}
	
    
    
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
