#include "Sorting.h"
  
using namespace std; 
  
struct Node 
{ 
    int num; 
    struct Node* left;
	struct Node* right; 
}; 
  
// A utility function to create a new BST Node 
struct Node *newNode(int data) 
{ 
    struct Node *temp = new Node; 
    temp->num = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Stores inoder traversal of the BST 
// in array[] 
void BST(Node *root, int array[], int &i) 
{ 
    if (root != NULL) 
    { 
        BST(root->left, array, i); 
        array[i++] = root->num; 
        BST(root->right, array, i); 
    } 
} 
  
/* A utility function to insert a new 
   Node with given num in BST */
Node* insert(Node* node, int data) 
{ 
    // If the tree is empty, return a new Node
    if (node == NULL) 
		return newNode(data); 
  
    // Otherwise, recurse down the tree
    if (data < node->num) 
        node->left  = insert(node->left, data); 
    else if (data > node->num) 
        node->right = insert(node->right, data); 
  
    // return Node pointer
    return node; 
} 
  
// This function sorts array[0..n-1] using Tree Sort 
void treeSort(int array[], int n) 
{ 
    struct Node *root = NULL; 
  
    // Construct the BST 
    root = insert(root, array[0]); 
    for (int i=1; i<n; i++) 
        insert(root, array[i]); 
  
    // Store inorder traversal of the BST 
    // in array[] 
    int i = 0; 
    BST(root, array, i); 
} 
  
