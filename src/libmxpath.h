#ifndef LIBMXPATH_H
#define LIBMXPATH_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>
//#include "libmx/inc/libmx.h"
#include "../libmx/inc/libmx.h"
//#include <string.h>

/* Определяем элемент списка */
// typedef struct list_node {
//     struct list_node *next;
//     void *data;
// } list_node_t;

// /* Определяем сам список */
// typedef struct list {
//     int size; /* Размер списка */
//     list_node_t *head;
//     list_node_t *tail;
// } list_t;

// // Определим структуру данных для нашего дерева:
// typedef struct tree_node {
//     struct tree_node * left; /* указатель на левую вершину */
//     struct tree_node * rigth; /* указатель на правую вершину */
//     void *data; /* указатель на хранимые в вершине данные */
//     int mark;  /* необходимая при обходе пометка */
// } tree_node_t;


// // Так же нужно определить указатель на функцию которая быдет 
// // вызывается для обработки данных находящихся в обрабатываемой вершине.
// typedef void (*visit_node_f)(tree_node_t *node, void *visit_data);

//----- to libmx
void mx_printerr(const char *s);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isalpha(int c);

//----- local specific functions only for pathfinder
void mx_errors_pf(int c, char *v[]);
char **mx_get_arr_islands(int G, char *str);
int **mx_get_matrix(int G, char *str);




//char **read_pic(char *v, int *h, int *w);

#endif
