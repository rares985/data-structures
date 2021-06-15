#ifndef DOUBLE_LINKED_LIST_NODE_H_
#define DOUBLE_LINKED_LIST_NODE_H_

template <typename T>
struct DoubleLinkedListNode {
    T                    *data;
    DoubleLinkedListNode *next;
    DoubleLinkedListNode *prev;
};


#endif /* DOUBLE_LINKED_LIST_NODE_H_ */
