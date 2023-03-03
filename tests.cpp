#include <binary_tree.h>
#include <binary_tree_node.h>
// #include <binary_search_tree.h>

#include <memory>
#include <cassert>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

static void test_binary_tree_node()
{
    BinaryTreeNode<char> ll{'D'};
    BinaryTreeNode<char> lr{'E'};
    BinaryTreeNode<char> l{'B', &ll, &lr};
    BinaryTreeNode<char> rl{'F'};
    BinaryTreeNode<char> rr{'G'};
    BinaryTreeNode<char> r{'C', &rl, &rr};
    BinaryTreeNode<char> x{'A', &l, &r};

    std::cout << x << "\n";

    std::cout << "PREORDER TRAVERSAL: " << x.Preorder() << "\n";
    std::cout << "INORDER TRAVERSAL: " << x.Inorder() << "\n";
    std::cout << "POSTORDER TRAVERSAL: " << x.Postorder() << "\n";

    std::cout << x.Find('G') << "\n";
}

static void test_binary_tree()
{
    BinaryTree<int> ll{9};
    BinaryTree<int> lr{16};
    BinaryTree<int> rl{21};
    BinaryTree<int> rr{23};

    BinaryTree<int> r{22, &rl, &rr};

    BinaryTree<int> l{19, &ll, &lr};

    BinaryTree<int> x{14, &l, &r};

    std::cout << x << "\n";
    std::cout << "DEPTH: " << x.Depth() << "\n";
    std::cout << "NB NODES: " << x.NbNodes() << "\n";
}
int main()
{
    test_binary_tree();
    return 0;
}
