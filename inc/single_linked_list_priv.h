#ifndef SINGLE_LINKED_LIST_PRIV_H_
#define SINGLE_LINKED_LIST_PRIV_H_

typedef struct sll_node {
  void        *data;
  struct sll_node *next;
} sll_node_t;

#endif /* SINGLE_LINKED_LIST_PRIV_H_ */