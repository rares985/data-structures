#include <single_linked_list.h>
#include <double_linked_list.h>
#include <stack.h>
#include <queue.h>
#include <graph.h>
#include <vector.h>
// #include <sort.h>

#include <binary_search_tree.h>

#include <unique_ptr.h>
#include <shared_ptr.h>

#include "SHA256.h"

#include <memory>
#include <cassert>
#include <vector>
#include <sstream>
#include <map>
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

// static void test_utils(void)
// {
//     Vector<int> v{5};
//     v.PushBack(5);
//     v.PushBack(4);
//     v.PushBack(3);
//     v.PushBack(2);
//     v.PushBack(1);

//     Sorter::BubbleSort(v);
//     std::cout << "BUBBLE SORT: " << v << "\n";

//     v = Vector<int>{5};
//     v.PushBack(5);
//     v.PushBack(4);
//     v.PushBack(3);
//     v.PushBack(2);
//     v.PushBack(1);

//     Sorter::InsertionSort(v);
//     std::cout << "INSERTION SORT: " << v << "\n";

//     v = Vector<int>{5};
//     v.PushBack(5);
//     v.PushBack(4);
//     v.PushBack(3);
//     v.PushBack(2);
//     v.PushBack(1);

//     /* TODO - Not working OK */
//     Sorter::SelectionSort(v);
//     std::cout << "SELECTION SORT: " << v << "\n";

//     v = Vector<int>{5};
//     v.PushBack(5);
//     v.PushBack(4);
//     v.PushBack(3);
//     v.PushBack(2);
//     v.PushBack(1);

//     Sorter::QuickSort(v);
//     std::cout << "QUICK SORT: " << v << "\n";
// }

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

static void test_binary_tree()
{
    // 2
    //  3
    //      5
    //      6
    //  4
    //      7
    //      8
    BinaryTree<int> ll{9};
    BinaryTree<int> lr{16};
    BinaryTree<int> rl{21};
    BinaryTree<int> rr{23};

    BinaryTree<int> l{14, &ll, &lr};
    BinaryTree<int> r{22, &rl, &rr};

    BinaryTree<int> x{19, &l, &r};

    std::cout << x << "\n";
    // std::cout << "Inorder traversal: " << x.Inorder() << "\n";
    // std::cout << x.Str(0) << "\n";
}

static void test_bst()
{
    BinarySearchTree<int> x{100};

    x.Insert(50);
    x.Insert(150);
    x.Insert(125);
    std::cout << x << "\n";
    x.Insert(200);
    std::cout << x << "\n";
}

int main()
{
    // test_binary_tree();
    test_bst();

    // test_list_comprehensive();

    // test_vector();
    // std::cout << "Vector Test ------------- OK\n";
    // test_utils();
    // std::cout << "Utils Test ------------- OK\n";
    test_sll();
    std::cout << "SLL Test ------------- OK\n";
    // test_dll();
    // std::cout << "DLL Test ------------- OK\n";
    // test_stack();
    // std::cout << "Stack Test ------------- OK\n";
    // test_queue();
    // std::cout << "Queue Test ------------- OK\n";
    // test_shared_ptr();
    // std::cout << "Shared PTR Test ------------- OK\n";
    // test_graph();
    // std::cout << "Graph Test ------------- OK\n";

    // SHA256 sha2;
    // sha2.update(std::string("test"));
    // uint8_t *digest = sha2.digest();
    // std::cout << SHA256::toString(digest) << "\n";
    // delete[] digest;

    return 0;
}