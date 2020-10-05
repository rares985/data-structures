#include "string.h"
#include "stdio.h"

#include "log.h"
#include "types.h"
#include "hashtable.h"

static unsigned int hash(const char *str, unsigned int hash_length);


static unsigned int hash(const char *str, unsigned int hash_length)
{
	unsigned int hash = 5381;
	int c;

	while ((c = *str++) != 0)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash % hash_length);
}


int ht_create(hashtable_t **ht, uint32_t size)
{
	int ret = ERR_OK;

	if (!ht || size < 1)
	{
		ret = ERR_INVALID_PARAMS;
	}
	else
	{
		*ht = calloc(1, sizeof(hashtable_t));
		if (NULL == *ht)
		{
			ret = ERR_NO_MEMORY;
		}
		else
		{
			/* Allocate bucket table */
			(*ht)->table = calloc(size, sizeof(bucket_t));
			if ((*ht)->table == NULL)
			{
				ret = ERR_NO_MEMORY;
			}
			else
			{
				(*ht)->size = size;
				for (unsigned int i = 0; i < size; i++)
				{
					/* All buckets are empty at beginning */
					ret = sll_create(&(*ht)->table[i]);
				}
			}
		}
	}

	return ret;
}


int ht_destroy(hashtable_t **ht)
{
	int ret = ERR_OK;
	if (!ht || !(*ht)->table)
	{
		LOG_ERR("Invalid params!");
		ret = ERR_INVALID_PARAMS;
	}
	else
	{
		for(unsigned int i = 0; i < (*ht)->size; i++)
		{
			sll_destroy(&(*ht)->table[i]);
		}

		free((*ht)->table);
		(*ht)->table = NULL;

		free(*ht);
		*ht = NULL;
	}
	return ret;
}

int ht_add(hashtable_t *ht, void *data, size_t data_size)
{
	int ret = ERR_OK;
	uint32_t index = hash(data, ht->size);

	bucket_t *bkt = ht->table[index];

	ret = sll_add_end(bkt, data, data_size);

	return ret;
}

int ht_find(hashtable_t *ht, void *data)
{
	int ret = ERR_OK;
	if (!ht)
	{
		ret = ERR_INVALID_PARAMS;
	}
	else
	{
		uint32_t index = hash(data, ht->size);
		ret = sll_find(ht->table[index], data);
	}

	return ret;
}


void ht_print_bucket(hashtable_t *ht, uint32_t index)
{
	sll_print(ht->table[index]);
}

void ht_print(hashtable_t *ht)
{
	for(unsigned int i = 0; i < ht->size; i++) {
		LOG_INF_NOENDL("[%d]: ", i);
		ht_print_bucket(ht, i);
	}
}

