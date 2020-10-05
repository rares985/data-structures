#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "hashtable_priv.h"

int ht_create(hashtable_t **ht, uint32_t size);
int ht_destroy(hashtable_t **ht);

int ht_add(hashtable_t *ht, void *data, size_t data_size);
int ht_find(hashtable_t *ht, void *data);


void ht_print_bucket(hashtable_t *ht, uint32_t index);
void ht_print(hashtable_t *ht);

#endif /* HASHTABLE_H_ */