// #include <binary_search_tree.h>

#include <memory>
#include <cassert>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <binary_tree_node.h>
#include <binary_search_tree.h>

#include <min_heap.h>

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

int main()
{
    test_bst();
    test_min_heap();
    return 0;
}
