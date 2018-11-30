#include "Sorting.h"
  
using namespace std; 

/*
    This sorting algorithm builds a binary search tree from the randomized 
    data and once complete, does an in-order traversal of the tree, 
    overwriting the original data with the sorted order. This is expected 
    to be pretty bad with the nearly sorted, and terrible with the 
    reverse-sorted arrays
    -Zack
*/

// main logic of tree sort
void treeSort(int * array, long int n) 
{ 
    //start with an empty tree
    struct Node *root = NULL; 
  
    // Construct the BST 
    root = insert(root, array[0]); 
    for (int i = 1; i < n; ++i) 
        insert(root, array[i]); 
  
    // Store inorder traversal of the BST in arrayTS 
    int i = 0; 
    rewrite(root, array, i); 
} 

// Writes traversal of the BST into arrayTS (overwriting original data)
void rewrite(Node *root, int * array, int &i) 
{ 
    if (root != NULL) 
    { 
        rewrite(root->left, array, i); 
        array[i] = root->num; 
        ++i;
        rewrite(root->right, array, i); 
    } 
} 
  
// A helper function to add a node to the tree
Node* insert(Node* node, int data) 
{ 
    // empty tree: new node free!
    if (node == NULL) 
		return newNode(data); 
  
    // Otherwise, recurse down the tree
    if (data < node->num) 
        node->left  = insert(node->left, data); 
    else if (data >= node->num) 
        node->right = insert(node->right, data); 
  
    // return Node pointer
    return node; 
} 

// A utility function to create a new BST Node 
struct Node *newNode(int data) 
{ 
    struct Node *temp = new Node; 
    temp->num = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}   
  
