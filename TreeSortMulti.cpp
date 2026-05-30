#include "Sorting.h"

#include <set>

/*
    Tree Sort using std::multiset

    Uses the standard library's ordered tree container to keep values sorted.
    This avoids the worst-case degeneration of a plain unbalanced BST.
*/

void treeSort(int* array, long int n)
{
    if (array == nullptr || n <= 1)
    {
        return;
    }

    std::multiset<int> tree;

    for (long int i = 0; i < n; ++i)
    {
        tree.insert(array[i]);
    }

    long int index = 0;

    for (int value : tree)
    {
        array[index] = value;
        ++index;
    }
}