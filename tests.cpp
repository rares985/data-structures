// #include <binary_search_tree.h>

#include <memory>
#include <cassert>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <binary_tree_node.h>
#include <binary_search_tree.h>
#include <unique_ptr.h>
#include <graph.h>
#include <algorithm>
#include <sstream>
#include <istream>
#include <ostream>

#include <heap.h>

template <typename T>
std::string vec2String(std::vector<T> vec)
{
    std::stringstream ss;
    for (auto &elem : vec)
        ss << elem << " ";
    return ss.str();
}

static void test_bst()
{
    BinarySearchTree<int> *tree = new BinarySearchTree<int>{};
    tree->Insert(50);
    tree->Insert(19);
    tree->Insert(28);
    tree->Insert(40);
    tree->Insert(16);
    tree->Insert(70);
    tree->Insert(55);
    tree->Insert(56);
    tree->Insert(17);
    tree->Insert(90);
    tree->Display();
    std::cout << "\n"
              << tree->MaxDepth();

    for (auto &elem : tree->ToVector())
    {
        std::cout << elem << " ";
    }

    delete tree;
}

template <typename T>
struct SmallerPriority
{
    bool operator()(const T &lhs, const T &rhs)
    {
        return lhs.priority < rhs.priority;
    }
};

template <typename T>
struct LargerPriority
{
    bool operator()(const T &lhs, const T &rhs)
    {
        return lhs.priority > rhs.priority;
    }
};

struct PriorityHolder
{
    int priority;
    int data;

    PriorityHolder(int p, int d) : priority(p), data(d) {}
    PriorityHolder() : priority(-1), data(-1) {}

    friend std::ostream &operator<<(std::ostream &os, const PriorityHolder &rhs)
    {
        os << rhs.priority << " " << rhs.data;
        return os;
    }
};

using PQueueMin = Heap<PriorityHolder, SmallerPriority<PriorityHolder>>;
using PQueueMax = Heap<PriorityHolder, LargerPriority<PriorityHolder>>;

static void
test_min_heap()
{
    PQueueMin *mh = new PQueueMin{20};
    std::vector<PriorityHolder> elems = {{2, 100}, {3, 500}, {1, 400}};

    for (auto &elem : elems)
    {
        mh->Insert(elem);
    }
    std::cout << "Minimum is : " << mh->Pop() << "\n";

    delete mh;
}

static void test_max_heap()
{
    PQueueMax *mh = new PQueueMax{20};
    std::vector<PriorityHolder> elems = {{2, 100}, {3, 500}, {1, 400}};

    for (auto &elem : elems)
    {
        mh->Insert(elem);
    }
    std::cout << "Maximum is : " << mh->Pop() << "\n";

    delete mh;
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
    // test_bst();
    test_min_heap();
    test_max_heap();

    return 0;
}
