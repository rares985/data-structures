#include "stdlib.h"

#include "single_linked_list.h"
#include "single_linked_list_priv.h"
#include "string.h"
#include "log.h"
#include "types.h"

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


int sll_create(single_linked_list_t **list)
{
	int ret = ERR_OK;

	if (!list)
	{
		LOG_ERR("%s: Invalid input parameters!", __FUNCTION__);
		ret = ERR_INVALID_PARAMS;
	}
	else
	{
		*list = (single_linked_list_t*) calloc(1, sizeof(single_linked_list_t));
		if (NULL == *list)
		{
			LOG_ERR("Memory allocation failed!");
			ret = ERR_NO_MEMORY;
		}
		else
		{
			(*list)->head = NULL;
		}
	}

	return ret;
}


int sll_destroy(single_linked_list_t **list)
{
	node_t *it = NULL;
	node_t *temp = NULL;
	int ret = ERR_OK;

	if (NULL == list)
	{
		ret = ERR_INVALID_PARAMS;
	}
	else if (NULL == *list)
	{
		ret = ERR_OK;
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

		free(*list);
		*list = NULL;
	}

	return ret;
}


int sll_add_start(single_linked_list_t *list, void *data, size_t data_size)
{
	int ret = ERR_OK;

	if (!list || !data)
	{
		LOG_ERR("%s: Null input parameter!", __FUNCTION__);
		ret = ERR_INVALID_PARAMS;
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
		else
		{
			ret = ERR_NO_MEMORY;
			LOG_ERR("Failed to allocate memory for new node!");
		}
	}
	return ret;
}


int sll_add_end(single_linked_list_t *list, void *data, size_t data_size)
{
	node_t *it = NULL;
	int ret = ERR_OK;

	if (!list || !data)
	{
		ret = ERR_INVALID_PARAMS;
	}
	else if (!list->head)
	{
		ret = sll_add_start(list, data, data_size);
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
		else
		{
			ret = ERR_NO_MEMORY;
			LOG_ERR("Failed to allocate memory for new node!");
		}
	}
	return ret;
}


int sll_add_pos(single_linked_list_t *list, void *data, size_t data_size, int pos)
{
	int i = 0;
	node_t *prev = NULL;
	node_t *it = NULL;
	int ret = ERR_OK;

	if (!list || !data || pos < 0)
	{
		LOG_ERR("Invalid input parameters!");
		ret = ERR_INVALID_PARAMS;
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
			else
			{
				ret = ERR_NO_MEMORY;
				LOG_ERR("Failed to allocate memory for new node!");
			}
		}
	}
	return ret;
}


int sll_remove_start(single_linked_list_t *list)
{
	node_t *temp = NULL;
	int ret = ERR_OK;

	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
		ret = ERR_INVALID_PARAMS;
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
	return ret;
}


int sll_remove_end(single_linked_list_t *list)
{
	node_t *prev = NULL;
	node_t *it = NULL;
	int ret = ERR_OK;

	if (!list)
	{
		LOG_ERR("Invalid input parameters!");
		ret = ERR_INVALID_PARAMS;
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
	return ret;
}


int sll_remove_pos(single_linked_list_t *list, int pos)
{
	int i = 0;
	node_t *it = NULL;
	node_t *prev = NULL;
	int ret = ERR_OK;

	if (NULL == list)
	{
		LOG_ERR("Invalid input parameters");
		ret = ERR_INVALID_PARAMS;
	}
	else if (NULL == list->head)
	{
		LOG_INF("List is empty, can not remove from pos %d", pos);
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
	return ret;
}


int sll_find(single_linked_list_t *list, void *data)
{
	int ret = ERR_OK;
	int index_found = -1;
	int i = 0;
	node_t *it = NULL;

	if (!list || !data)
	{
		ret = ERR_INVALID_PARAMS;
	}
	else
	{
		it = list->head;
		while(it)
		{
			if (0 == memcmp(it->data, data, sizeof(*it->data)))
			{
				index_found = i;
			}
			it = it->next;
			i += 1;
		}
	}
	return (ret == ERR_OK ? index_found : ret);
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

	if (list)
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