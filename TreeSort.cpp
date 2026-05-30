#include "Sorting.h"
  
/*
    Tree Sort

    Builds a binary search tree from the input, then writes the sorted
    values back to the original array using an in-order traversal.

    This version uses a plain unbalanced BST, so sorted and reverse-sorted
    input can degrade to O(n²).
*/

namespace
{
    struct TreeNode
    {
        int value;
        long int count;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* createNode(int value)
    {
        return new TreeNode{ value, 1, nullptr, nullptr };
    }

    TreeNode* insert(TreeNode* node, int value)
    {
        if (node == nullptr)
        {
            return createNode(value);
        }

        if (value < node->value)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            ++node->count;
        }

        return node;
    }

    void writeInOrder(TreeNode* node, int* array, long int& index)
    {
        if (node == nullptr)
        {
            return;
        }

        writeInOrder(node->left, array, index);

        for (long int i = 0; i < node->count; ++i)
        {
            array[index] = node->value;
            ++index;
        }

        writeInOrder(node->right, array, index);
    }

    void deleteTree(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void treeSortNaive(int* array, long int n)
{
    if (array == nullptr || n <= 1)
    {
        return;
    }

    TreeNode* root = nullptr;

    for (long int i = 0; i < n; ++i)
    {
        root = insert(root, array[i]);
    }

    long int index = 0;
    writeInOrder(root, array, index);

    deleteTree(root);
}