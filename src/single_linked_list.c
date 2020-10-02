#include "stdlib.h"

#include "single_linked_list.h"
#include "single_linked_list_priv.h"
#include "string.h"
#include "log.h"

typedef sll_node_t node_t;

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

void sll_create(single_linked_list_t **list)
{
	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else
	{
		*list = (single_linked_list_t*) calloc(1, sizeof(single_linked_list_t));
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

void sll_destroy(single_linked_list_t **list)
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


void sll_add_start(single_linked_list_t *list, void *data, size_t data_size)
{
	if (!list)
	{
		LOG_ERR("Null input parameter!");
	}
	else
	{
		node_t *elem = allocate_node(data_size);
		if (elem)
		{
			memcpy(elem->data, data, data_size);
			elem->next = list->head;
			list->head = elem;
		}
	}
}

void sll_add_end(single_linked_list_t *list, void *data, size_t data_size)
{
	node_t *it = NULL;

	if (!list)
	{
		LOG_ERR("Null input parameter!");
	}
	else
	{
		node_t *elem = allocate_node(data_size);
		if (elem)
		{
			memcpy(elem->data, data, data_size);
			elem->next = NULL;

			it = list->head;
			while(it->next)
			{
				it = it->next;
			}

			it->next = elem;
		}
	}
}


void sll_add_pos(single_linked_list_t *list, void *data, size_t data_size, int pos)
{
	int i = 0;
	node_t *prev = NULL;
	node_t *it = NULL;

	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else if (0 == pos)
	{
		sll_add_start(list, data, data_size);
	}
	else
	{
		it = list->head;
		while(it && i < pos)
		{
			prev = it;
			it = it->next;
			i += 1;
		}

		if (i < pos)
		{
			LOG_ERR("Cannot insert at %d, list is only %d long!", pos, i);
		}
		else
		{
			node_t *elem = allocate_node(data_size);
			if (elem)
			{
				memcpy(elem->data, data, data_size);

				elem->next = it;
				prev->next = elem;
			}
		}
	}
}


void sll_remove_start(single_linked_list_t *list)
{
	node_t *temp = NULL;

	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else
	{
		temp = list->head;
		list->head = list->head->next;

		free(temp->data);
		temp->data = NULL;

		free(temp);
		temp = NULL;
	}
}

void sll_remove_end(single_linked_list_t *list)
{
	node_t *prev = NULL;
	node_t *it = NULL;

	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
	}
	else
	{
		it = list->head;
		while(it->next)
		{
			prev = it;
			it = it->next;
		}

		prev->next = NULL;

		free(it->data);
		it->data = NULL;

		free(it);
		it = NULL;
	}
}

void sll_remove_pos(single_linked_list_t *list, int pos)
{
	int i = 0;
	node_t *it = NULL;
	node_t *prev = NULL;

	if ((NULL == list) || (NULL == list->head))
	{
		LOG_ERR("List is empty!");
	}
	else if (0 == pos)
	{
		sll_remove_start(list);
	}
	else
	{
		it = list->head;
		while(i < pos)
		{
			prev = it;
			it = it->next;
			i += 1;

			if (!it)
			{
				LOG_ERR("Cannot remove from position %d, list only has %d elements!", pos, i);
				break;
			}
		}

		if (NULL != it)
		{
			/* While exited because i == pos */
			prev->next = it->next;

			free(it->data);
			it->data = NULL;

			free(it);
			it = NULL;
		}
	}
}


int sll_length(single_linked_list_t *list)
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


void sll_print(single_linked_list_t *list)
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