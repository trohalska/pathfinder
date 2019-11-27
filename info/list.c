//------------------------------------------------------header.h
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
//------------------------------------------------------

/* Инициализация массива */
list_t *create_list(void) {
    list_t *lt = malloc(sizeof(list_t));
    lt->size = 0;
    lt->head = NULL;
    lt->tail = lt->head;
    return lt;
}

/* Добавляем элемент в начало списка */
void list_push(list_t *lt, void * data) {
    list_node_t * node = malloc(sizeof(list_node_t));
    node->data = data;
    node->next = lt->head;
    lt->head = node;
    lt->size += 1;
}

/* Извлекаем элемент из начала списка */
void *list_pop(list_t *lt) 
{
    if(lt->size == 0){
        /* Список пуст */
        return NULL;
    }

    list_node_t *node = lt->head;
    void *ret_val = node->data;

    lt->size -= 1;
    lt->head = node->next;

    free(node);

    if(lt->size == 0){
        /* Это был последний элемент */
        lt->head = NULL;
        lt->tail = NULL;
    }
    return ret_val;
}

/* Добавляем элемент в конец списка */
void list_push_back(list_t *lt, void *data)
{
    list_node_t *node = malloc(sizeof(list_node_t));
    node->data = data;
    if(lt->tail != NULL)
        lt->tail->next = node;
    else {
        lt->head = node;
    }

    lt->tail = node;
    lt->size += 1;
}

Теперь можно использовать этот список и как очередь и как стек.
Пример использования как стек:

list_t *st = create_list();
int data = 0, *ptr;
/* Добавляем в начало списка */
list_push(st, &data);
/* Извлекаем из начала списка*/
ptr = (int *)list_pop(st);g

А вот пример использования как очереди:

list_t *queue = create_list();
int data = 0, *ptr;

/* Добавляем в конец списка */
list_push_back(queue, &data);
/* Извлекаем из начала списка*/
ptr = (int *)list_pop(queue);


void dfs(tree_node_t * root, visit_node_f node_function, void *visit_data)
{
    list_t *st = create_list();

    list_push(st, root);

    while(st->size != 0) {
        tree_node_t * node = st->head->data;
        /* посетить вершину, если это не сделали раньше */
        if(node->mark != 1){
            (*node_function)(node, visit_data);
            node->mark = 1;
        }

        if(node->left != NULL && !node->left->mark) {
            list_push(st, node->left);
            continue;
        }

        if(node->rigth != NULL && !node->rigth->mark) {
            list_push(st, node->rigth);
            continue;
        }
        /* Извлекаем обработанную вершину из стека */
        tree_node_t * rel_node = (tree_node_t *)list_pop(st);
    }

    free(st);
}