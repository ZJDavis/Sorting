#include <iostream> //for writing to console
#include <fstream> //for writing to file
#include <chrono> //for Timer class
#include <ctime> //also for Timer class
#include <cmath> //2+2 is 4, -1 is 3. QUICK MAFS
#include <cstdlib> //standard stuff

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
void swap(int * a, int * b);
int quickSortPartition(int * array, int low, int high);
void quickSortHelper(int * array, int low, int high);
void quickSort(int* array, long int n);
void quickSort2(int* array, long int n);
//merge sort functions
void mergeSort(int* array, long int n);
void merge(int * array, int left, int middle, int right);
void mergeSortHelper(int * array, int left, int right);

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


