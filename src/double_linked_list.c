#include "string.h"
#include "stdlib.h"

#include "log.h"
#include "double_linked_list.h"
#include "double_linked_list_priv.h"

typedef dll_node_t node_t;

static node_t *allocate_node(size_t data_size)
{
	node_t *elem = NULL;
	elem = calloc(1, sizeof(node_t));
	if (!elem)
	{
		LOG_ERR("Memory allocation failed");
	}
	else
	{
		elem->data = calloc(1, data_size);
		if (!elem->data)
		{
			LOG_ERR("Memory allocation failed!");
		}
	}
	return elem;
}

void dll_create(double_linked_list_t **list)
{
	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else
	{
		*list = (double_linked_list_t*) calloc(1, sizeof(double_linked_list_t));
		if (NULL == *list)
		{
			LOG_ERR("Memory allocation failed!");
		}
		else
		{
			(*list)->head = NULL;
		}
	}
}


void dll_destroy(double_linked_list_t **list)
{
	node_t *it = NULL;
	node_t *temp = NULL;

	if (NULL == list)
	{
		LOG_ERR("Null input parameter!");
	}
	else if ((NULL == *list) || (NULL == (*list)->head))
	{
		LOG_ERR("List already empty!");
	}
	else
	{
		it = (*list)->head;
		while (it)
		{
			temp = it;
			it = it->next;

			free(temp->data);
			temp->data = NULL;

			free(temp);
			temp = NULL;
		}
	}
	free(*list);
	*list = NULL;
}


void dll_add_start(double_linked_list_t *list, void *data, size_t data_size)
{
	node_t *elem = allocate_node(data_size);
	if (elem)
	{
		memcpy(elem->data, data, data_size);
		elem->next = list->head;
		elem->prev = NULL;

		list->head = elem;
	}
}


void dll_add_end(double_linked_list_t *list, void *data, size_t data_size)
{
	node_t *it = NULL;
	node_t *elem = NULL;

	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else if (!list->head)
	{
		dll_add_start(list, data, data_size);
	}
	else
	{
		/* Iterate list to find last position */
		it = list->head;
		
		while(it->next)
		{
			it = it->next;
		}

		elem = allocate_node(data_size);
		if (elem)
		{
			memcpy(elem->data, data, data_size);

			/* new element is the last in the list */
			elem->next = NULL;
			elem->prev = it;
			it->next = elem;
		}
	}
}


void dll_add_pos(double_linked_list_t *list, void *data, size_t data_size, int pos)
{
	int len = dll_length(list);

	if (!list || !data || pos < 0)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else if (pos > len)
	{
		LOG_ERR("Cannot add to position %d: List only has %d elements!", pos, len);
	}
	else if (pos == len)
	{
		dll_add_end(list, data, data_size);
	}
	else
	{
		node_t *it = list->head;
		int i = 0;
		while(i < pos)
		{
			it = it->next;
			i += 1;
		}

		node_t *elem = allocate_node(data_size);
		if (elem)
		{
			memcpy(elem->data, data, data_size);

			it->prev->next = elem;
			elem->next = it;
			
			elem->prev = it->prev;
			it->prev = elem;
		}
	}
}


void dll_remove_start(double_linked_list_t *list)
{
	node_t *temp = NULL;

	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else
	{
		temp = list->head;

		if (list->head->next)
		{
			/* Only if there are more than 1 elements in list */
			list->head->next->prev = NULL;
		}
		list->head = list->head->next;

		free(temp->data);
		temp->data = NULL;

		free(temp);
		temp = NULL;
	}
}


void dll_remove_end(double_linked_list_t *list)
{
	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else if (!list->head->prev)
	{
		/* List has one element */
		dll_remove_start(list);
	}
	else
	{
		node_t *it = list->head;
		while(it->next)
		{
			it = it->next;
		}

		it->prev->next = NULL;

		free(it->data);
		it->data = NULL;

		free(it);
		it = NULL;

	}
}


void dll_remove_pos(double_linked_list_t *list, int pos)
{
	(void)list;
	(void)pos;
}




int dll_length(double_linked_list_t *list)
{
	node_t *it = NULL;
	int len = 0;

	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
		len = -1;
	}
	else
	{
		it = list->head;
		while(it)
		{
			it = it->next;
			len += 1;
		}
	}

	return len;
}


void dll_print(double_linked_list_t *list)
{
	node_t *it = NULL;

	if (!list)
	{
		LOG_ERR("Null input parameter!");
	}
	else
	{
		it = list->head;
		while (it)
		{
			LOG_INF_NOENDL("%d->", *(int*)it->data);
			it = it->next;
		}
		LOG_INF("(null)");
	}
}

