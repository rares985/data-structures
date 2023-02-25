#include <single_linked_list.h>
#include <double_linked_list.h>
#include <stack.h>
#include <queue.h>
#include <graph.h>
#include <vector.h>

#include <unique_ptr.h>
#include <shared_ptr.h>

#include "SHA256.h"

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

static void test_shared_ptr(void)
{
    SharedPtr<int> sptr1{new int{2}};
    SharedPtr<int> sptr2{sptr1};
    SharedPtr<int> sptr3{std::move(sptr2)};

    std::cout << *sptr3 << "\n";
}

static void test_vector(void)
{
    Vector<int> v{2};

    v.PushBack(1);
    v.PushBack(2);

    std::cout << v[0] << v[1] << "\n";

    std::cout << v << "\n";
}

static void test_sll(void)
{
    UniquePtr<SingleLinkedList<int>> lst{new SingleLinkedList<int>{}};
    lst->PushBack(5);
    lst->PushBack(6);
    lst->PushBack(7);
    lst->PushFront(4);
    lst->PushFront(3);
    lst->PushFront(2);
    lst->PushFront(1);
    lst->PushFront(0);

    assert(lst->Size() == 8);

    std::cout << *lst << "\n";
    lst->Reverse();
    std::cout << *lst << "\n";
    lst->Reverse();
    std::cout << *lst << "\n";

    int ret;

    for (int i = 7; i >= 0; i--)
    {
        ret = lst->PopBack();
        assert(ret == i);
    }

    ret = lst->PopFront();
    assert(ret == 0);

    assert(lst->Size() == 0);
    assert(lst->Empty() == true);
    assert(lst->HasCycle() == false);
}

static void test_dll(void)
{
    UniquePtr<DoubleLinkedList<int>> lst{new DoubleLinkedList<int>{}};

    lst->PushBack(2);
    lst->PushBack(3);
    lst->PushBack(4);
    lst->PushFront(1);

    assert(lst->Size() == 4);

    int ret;

    ret = lst->PopBack();
    assert(ret == 4);

    ret = lst->PopBack();
    assert(ret == 3);

    ret = lst->PopBack();
    assert(ret == 2);

    ret = lst->PopBack();
    assert(ret == 1);

    assert(lst->Size() == 0);
    assert(lst->Empty() == true);
}

static void test_stack(void)
{
    UniquePtr<Stack<int>> st{new Stack<int>{}};

    st->Push(2);
    st->Push(3);
    st->Push(4);
    st->Push(5);

    assert(st->Size() == 4);
    assert(st->Top() == 5);

    int ret = st->Pop();
    assert(ret == 5);

    ret = st->Pop();
    assert(ret == 4);

    ret = st->Pop();
    assert(ret == 3);

    ret = st->Pop();
    assert(ret == 2);

    assert(st->Size() == 0);
    assert(st->Empty() == true);
}

static void test_queue(void)
{
    UniquePtr<Queue<int>> q{new Queue<int>{}};

    q->Push(1);
    q->Push(2);
    q->Push(3);
    q->Push(4);
    q->Push(5);

    assert(q->Size() == 5);
    assert(q->Front() == 1);
    assert(q->Back() == 5);

    int ret = q->Pop();
    assert(ret == 1);
    ret = q->Pop();
    assert(ret == 2);
    ret = q->Pop();
    assert(ret == 3);
    ret = q->Pop();
    assert(ret == 4);
    ret = q->Pop();
    assert(ret == 5);

    q.reset(new Queue<int>{});

    q->Push(1);
    q->Push(2);
    q->Push(3);
    q->Push(4);
    q->Push(5);
}

static void test_graph(void)
{
    UniquePtr<Graph> g{new Graph{9, false}};

    g->AddEdge(1, 2);
    g->AddEdge(2, 8);
    g->AddEdge(8, 3);
    g->AddEdge(3, 6);
    g->AddEdge(6, 7);

    g->AddEdge(3, 4);
    g->AddEdge(4, 5);
    g->AddEdge(5, 9);
    g->AddEdge(9, 1);
    g->AddEdge(4, 1);

    std::cout << *g << "\n";

    std::vector<int> traversal;

    assert(true == g->BFSTraversal(1, traversal));

    std::cout << "BFS Traversal: " << vec2String(traversal) << "\n";

    traversal.clear();
    assert(true == g->DFSTraversal(1, traversal));
    std::cout << "DFS Traversal: " << vec2String(traversal) << "\n";
}

int main()
{
    test_vector();
    std::cout << "Vector Test ------------- OK\n";
    test_sll();
    std::cout << "SLL Test ------------- OK\n";
    test_dll();
    std::cout << "DLL Test ------------- OK\n";
    test_stack();
    std::cout << "Stack Test ------------- OK\n";
    test_queue();
    std::cout << "Queue Test ------------- OK\n";
    test_shared_ptr();
    std::cout << "Shared PTR Test ------------- OK\n";
    test_graph();
    std::cout << "Graph Test ------------- OK\n";

    SHA256 sha2;
    sha2.update(std::string("test"));
    uint8_t *digest = sha2.digest();
    std::cout << SHA256::toString(digest) << "\n";
    delete[] digest;

    return 0;
}