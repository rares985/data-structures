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

#include <min_heap.h>

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

    for (auto &elem : std::vector<int>{100, 90, 80, 70, 60, 50, 40, 30, 20, 10})
    {
        mh->Insert(elem);
    }

    std::cout << "Minimum is : " << mh->ExtractMin();

    // std::cout << mh << "\n";

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
    return 0;
}
