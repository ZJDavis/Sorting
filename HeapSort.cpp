#include "Sorting.h"

using namespace std;

/* 
heapify creates the heap for heapsort. node i
is the root, and n is the size of the heap
-Adrian
*/
void heapify(int * array, long int n, long int i)
{
    int biggest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    //logical statements
    if (left < n && array[left] > array[biggest])
    	biggest = left;
    if (right < n && array[right] > array[biggest])
	    biggest = right;
    
    if (biggest != i)
    {
        swap(array[i], array[biggest]);
	    //recursion
	    heapify(array, n, biggest);
    }
}

void heapSort(int * array, long int n)
{
    //build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n-1; i >= 0; i--)
    {
        //move the current root to the end
	swap(array[0], array[i]);
	heapify(array, i, 0);
    }
}
