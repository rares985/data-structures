#ifndef HASHTABLE_PRIV_H_
#define HASHTABLE_PRIV_H_

#include "single_linked_list_priv.h"
#include "single_linked_list.h"
#include "types.h"

typedef single_linked_list_t    bucket_t;
typedef sll_node_t              node_t;
typedef struct hashtable {
    uint32_t size;
    bucket_t **table;
} hashtable_t;

#endif /* HASHTABLE_PRIV_H_ */