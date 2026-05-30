#include "Sorting.h"

#include <algorithm>

using namespace std;

/*
    Heap Sort

    In-place comparison sorting algorithm with O(n log n) time complexity.
    This implementation builds a max heap, then repeatedly moves the largest
    remaining element to the end of the array.
*/

void heapify(int * array, long int n, long int i)
{
    long int biggest = i;
    const long int left = 2*i + 1;
    const long int right = 2*i + 2;

    //logical statements
    if (left < n && array[left] > array[biggest]) {
        biggest = left;
    }

    if (right < n && array[right] > array[biggest]) {
        biggest = right;
    }
    
    if (biggest != i)
    {
        std::swap(array[i], array[biggest]);
	    //recursion
	    heapify(array, n, biggest);
    }
}

void heapSort(int * array, long int n)
{
    if (array == nullptr || n <= 1)
    {
        return;
    }

    //build the heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    for (int i = n-1; i >= 0; i--)
    {
        //move the current root to the end
	    std::swap(array[0], array[i]);
	    heapify(array, i, 0);
    }
}
