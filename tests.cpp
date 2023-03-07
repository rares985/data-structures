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

#include <min_heap.h>
#include <max_heap.h>

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

static void test_min_heap()
{
    MinHeap<int> *mh = new MinHeap<int>{20};
    std::vector<int> elems{100, 90, 80, 70, 60, 50, 40, 30, 20, 10};

    for (auto &elem : elems)
    {
        mh->Insert(elem);
    }
    auto it = std::min_element(elems.begin(), elems.end());
    std::cout << "Minimum is : " << mh->Pop() << " " << *it << "\n";

    delete mh;
}

static void test_max_heap()
{
    MaxHeap<int> *mh = new MaxHeap<int>{20};
    std::vector<int> elems{100, 90, 80, 70, 60, 50, 40, 30, 20, 10};

    for (auto &elem : elems)
    {
        mh->Insert(elem);
    }

    auto it = std::max_element(elems.begin(), elems.end());
    std::cout << "Maximum is : " << mh->Pop() << " " << *it << "\n";

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
    test_bst();
    test_min_heap();
    test_max_heap();
    return 0;
}
