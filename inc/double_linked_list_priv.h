#ifndef DOUBLE_LINKED_LIST_PRIV_H_
#define DOUBLE_LINKED_LIST_PRIV_H_

typedef struct dll_node {
  void            *data;
  struct dll_node *prev;
  struct dll_node *next;
} dll_node_t;

#endif /* DOUBLE_LINKED_LIST_PRIV_H_ */