#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <cstdlib> 

using namespace std;

//algorithms (modify the definitions if needed)

//heap sort functions
void heapify(int * array, long int n, long int i);
void heapSort(int * array, long int n);
//counting sort functions
void countingSort(int * array, long int n);
//tree sort functions
struct Node 
{ 
    int num; 
    struct Node* left;
	struct Node* right; 
}; 
struct Node *newNode(int data);
void treeSort(int* array, long int n);
void rewrite(Node *root, int *array, int &i);
Node* insert(Node* node, int data);
//cube sort functions
void cubeSort(int* array);
//quicksort functions
void quickSort(int* array, long int n);
void quickSort2(int* array, long int n);
//merge sort functions
void mergeSort(int* array, long int n);

//timer class
class Timer
{
public:
    void start();
    void stop();
    double elapsedSeconds();
    double elapsedMilliseconds();
    double elapsedNanoseconds();
};


