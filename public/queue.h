#ifndef QUEUE_H_
#define QUEUE_H_

#include "double_linked_list.h"
#include "double_linked_list_priv.h"

typedef struct queue {
    dll_node_t *front;
    dll_node_t *rear;
    int size;
    int capacity;
} queue_t;

int queue_create(queue_t **queue, int capacity);
int queue_destroy(queue_t **queue);

int queue_enqueue(queue_t *queue, void *data, size_t data_size);
int queue_dequeue(queue_t *queue, void *data, size_t data_size);
void *queue_peek(queue_t *queue);

int queue_size(queue_t *queue);
int queue_is_full(queue_t *queue);
int queue_is_empty(queue_t *queue);

void queue_print(queue_t *queue);


#endif /* QUEUE_H_ */