#include <single_linked_list.h>
#include <double_linked_list.h>
#include <stack.h>

#include <memory>
#include <cassert>

#include <iostream>

static void test_sll(void)
{
    SingleLinkedList<int> *lst = new SingleLinkedList<int>();
    lst->push_back(2);
    lst->push_back(3);
    lst->push_back(4);
    lst->push_front(1);

    assert(lst->size() == 4);

    int ret;

    ret = lst->pop_back();
    assert(ret == 4);

    ret = lst->pop_back();
    assert(ret == 3);

    ret = lst->pop_back();
    assert(ret == 2);

    ret = lst->pop_back();
    assert(ret == 1);

    assert(lst->size() == 0);
    assert(lst->empty() == true);

    delete lst;
}

static void test_dll(void)
{
    DoubleLinkedList<int> *lst = new DoubleLinkedList<int>();
    lst->push_back(2);
    lst->push_back(3);
    lst->push_back(4);
    lst->push_front(1);

    assert(lst->size() == 4);

    int ret;

    ret = lst->pop_back();
    assert(ret == 4);

    ret = lst->pop_back();
    assert(ret == 3);

    ret = lst->pop_back();
    assert(ret == 2);

    ret = lst->pop_back();
    assert(ret == 1);

    assert(lst->size() == 0);
    assert(lst->empty() == true);

    delete lst;

}

static void test_stack(void)
{
    Stack<int> *st = new Stack<int>();

    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);


    assert(st->size() == 4);
    assert(st->top() == 5);


    int ret = st->pop();
    assert(ret == 5);

    ret = st->pop();
    assert(ret == 4);

    ret = st->pop();
    assert(ret == 3);

    ret = st->pop();
    assert(ret == 2);

    assert(st->size() == 0);
    assert(st->empty() == true);

    delete st;

}


int main()
{
    test_sll();
    test_dll();
    test_stack();

    return 0;
}