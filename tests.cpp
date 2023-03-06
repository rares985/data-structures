// #include <binary_search_tree.h>

#include <memory>
#include <cassert>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <binary_tree_node.h>
#include <binary_search_tree.h>

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

    delete tree;
}

int main()
{
    test_bst();
    return 0;
}
