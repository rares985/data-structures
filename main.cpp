#include <single_linked_list.h>
#include <double_linked_list.h>
#include <stack.h>
#include <queue.h>
// #include <graph.h>
#include <unique_ptr.h>

#include <memory>
#include <cassert>
#include <vector>
#include <sstream>

#include <iostream>

static std::string vec2String(std::vector<int> vec)
{
    std::stringstream ss;

    ss << "[";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {

        ss << *it << (it != vec.end() - 1 ? " " : "]");
    }
    return ss.str();
}

static void test_sll(void)
{
    UniquePtr<SingleLinkedList<int>> lst{new SingleLinkedList<int>{}};
    lst->push_back(2);
    lst->push_back(3);
    lst->push_back(4);
    lst->push_front(1);
    lst->push_front(2);
    lst->push_front(3);
    lst->push_front(4);

    assert(lst->size() == 7);

    int ret;

    ret = lst->pop_back();
    assert(ret == 4);

    ret = lst->pop_back();
    assert(ret == 3);

    ret = lst->pop_back();
    assert(ret == 2);

    ret = lst->pop_back();
    assert(ret == 1);

    ret = lst->pop_back();
    assert(ret == 2);

    ret = lst->pop_back();
    assert(ret == 3);

    ret = lst->pop_back();
    assert(ret == 4);

    assert(lst->size() == 0);
    assert(lst->empty() == true);
}

static void test_dll(void)
{
    UniquePtr<DoubleLinkedList<int>> lst{new DoubleLinkedList<int>{}};

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
}

static void test_stack(void)
{
    UniquePtr<Stack<int>> st{new Stack<int>{}};

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
}

static void test_queue(void)
{
    UniquePtr<Queue<int>> q{new Queue<int>{}};

    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);

    assert(q->size() == 5);
    assert(q->front() == 1);
    assert(q->back() == 5);

    int ret = q->pop();
    assert(ret == 1);
    ret = q->pop();
    assert(ret == 2);
    ret = q->pop();
    assert(ret == 3);
    ret = q->pop();
    assert(ret == 4);
    ret = q->pop();
    assert(ret == 5);

    q.reset(new Queue<int>{});

    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);
}

// static void test_graph(void)
// {
//     Graph *g = new Graph(9, false);

//     g->add_edge(1, 2);
//     g->add_edge(2, 8);
//     g->add_edge(8, 3);
//     g->add_edge(3, 6);
//     g->add_edge(6, 7);

//     g->add_edge(3, 4);
//     g->add_edge(4, 5);
//     g->add_edge(5, 9);
//     g->add_edge(9, 1);
//     g->add_edge(4, 1);

//     std::cout << *g;

//     std::vector<int> traversal;

//     assert(true == g->bfs_traversal(1, traversal));

//     std::cout << "\nBFS Traversal: " << vec2String(traversal);

//     traversal.clear();
//     assert(true == g->dfs_traversal(1, traversal));
//     std::cout << "\nDFS Traversal: " << vec2String(traversal);

//     delete g;
// }

int main()
{
    test_sll();
    std::cout << "SLL Test ------------- OK\n";
    test_dll();
    std::cout << "DLL Test ------------- OK\n";
    test_stack();
    std::cout << "Stack Test ------------- OK\n";
    test_queue();
    std::cout << "Queue Test ------------- OK\n";
    // test_graph();

    return 0;
}