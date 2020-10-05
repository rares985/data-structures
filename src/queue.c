#include "string.h"
#include "stdlib.h"
#include "stdio.h"

#include "log.h"
#include "types.h"

#include "double_linked_list_priv.h"

#include "queue.h"
#include "queue_priv.h"

typedef dll_node_t node_t;


static node_t *allocate_node(size_t data_size);

static node_t *allocate_node(size_t data_size)
{
    node_t *elem = (node_t*) calloc(1, sizeof(node_t));
    if (elem)
    {
        elem->data = calloc(1, data_size);
        if (!elem->data)
        {
            free(elem);
            elem = NULL;
        }
        else
        {
            elem->next = NULL;
            elem->prev = NULL;
        }
    }
    return elem;
}

int queue_create(queue_t **queue, int capacity)
{
    int ret = ERR_OK;
    if (!queue)
    {
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        *queue = (queue_t*) calloc(1, sizeof(queue_t));
        if (NULL == *queue)
        {
            ret = ERR_NO_MEMORY;
        }
        (*queue)->front = NULL;
        (*queue)->rear = NULL;
        (*queue)->size = 0;
        (*queue)->capacity = capacity;
    }
    return ret;
}


int queue_destroy(queue_t **queue)
{
    int ret = ERR_OK;
    node_t *it = NULL;
    node_t *temp = NULL;

    if (!queue)
    {
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        it = (*queue)->front;
        while(it)
        {
            temp = it;
            it = it->next;

            free(temp->data);
            temp->data = NULL;

            free(temp);
            temp = NULL;
        }
        free(*queue);
        *queue = NULL;
    }
    return ret;
}


int queue_enqueue(queue_t *queue, void *data, size_t data_size)
{
    int ret = ERR_OK;
    if (!queue || !data)
    {
        ret = ERR_INVALID_PARAMS;
    }
    else if (queue->size == queue->capacity)
    {
        ret = ERR_STRUCTURE_FULL;
    }
    else
    {
        node_t *elem = allocate_node(data_size);
        if (elem)
        {
            memcpy(elem->data, data, data_size);

            if (!queue->front)
            {
                /* first in line */
                queue->front = elem;
            }
            else
            {
                queue->rear->next = elem;
                elem->prev = queue->rear;
            }
            queue->rear = elem;
            queue->size += 1;
        }
        else
        {
            ret = ERR_NO_MEMORY;
        }
    }
    return ret;
}


int queue_dequeue(queue_t *queue, void *data, size_t data_size)
{
    int ret = ERR_OK;
    node_t *temp = NULL;

    if (!queue)
    {
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        temp = queue->front;
        memcpy(data, queue->front->data, data_size);

        if (queue->front == queue->rear)
        {
            /* there is only one element in queue */
            queue->front = NULL;
            queue->rear = NULL;
        }
        else
        {
            queue->front = queue->front->next;
        }

        free(temp->data);
        temp->data = NULL;
        free(temp);
        temp = NULL;

        queue->size -= 1;
    }
    return ret;
}


void *queue_peek(queue_t *queue)
{
    void *ret = NULL;

    if (!queue)
    {
        ret = NULL;
    }
    else
    {
        ret = queue->front->data;
    }
    return ret;
}


int queue_size(queue_t *queue)
{
    int ret = ERR_OK;
    if (!queue)
    {
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        return queue->size;
    }
    return ret;
}


int queue_is_full(queue_t *queue)
{
    int ret = ERR_OK;
    if (!queue)
    {
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        ret = (queue->size == queue->capacity);
    }

    return ret;
}


int queue_is_empty(queue_t *queue)
{
    int ret = ERR_OK;
    if (!queue)
    {
        LOG_ERR("Invalid parameters.");
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        ret = (queue->size == 0);
    }
    return ret;
}

void queue_print(queue_t *queue)
{
    node_t *it = NULL;

    if (queue && queue->rear)
    {
        it = queue->front;
        while(it)
        {
            LOG_INF_NOENDL("%d->", *(int*)it->data);
            it = it->next;
        }
    }
    LOG_INF("(null)");
}

