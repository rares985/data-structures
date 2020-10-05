#include "string.h"

#include "stack.h"
#include "log.h"
#include "types.h"
#include "single_linked_list.h"

int stack_create(stack_t **stack)
{
    int ret = ERR_OK;
    if (!stack)
    {
        LOG_ERR("Invalid parameter. Cannot initialize stack!");
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        ret = sll_create(stack);
    }
    return ret;
}

int stack_push(stack_t *stack, void *data, size_t data_size)
{
    return sll_add_start(stack, data, data_size);
}

int stack_pop(stack_t *stack, void *data, size_t data_size)
{
    int ret = ERR_OK;
    if (!stack || !stack->head)
    {
        LOG_ERR("Cannot pop from null or empty stack!");
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        memcpy(data, stack->head->data, data_size);
        ret = sll_remove_start(stack);
    }
    return ret;
}

void *stack_peek(stack_t *stack)
{
    void *ret = NULL;
    if (!stack)
    {
        LOG_ERR("Empty stack has no top.");
        ret = NULL;
    }
    else
    {
        ret = stack->head->data;
    }

    return ret;
}

int stack_size(stack_t *stack)
{
    int ret = ERR_OK;
    if (!stack)
    {
        LOG_ERR("Invalid parameter. Cannot get size of null stack");
        ret = ERR_INVALID_PARAMS;
    }
    else {
        ret = sll_length(stack);
    }
    return ret;
}

int stack_destroy(stack_t **stack)
{
    int ret = ERR_OK;
    if (!stack)
    {
        LOG_ERR("Invalid parameter. Cannot destroy null stack!");
        ret = ERR_INVALID_PARAMS;
    }
    else
    {
        ret = sll_destroy(stack);
    }
    return ret;
}