#include "Sorting.h"

using namespace std;

void merge(int * array, int left, int middle, int right)
{
    int x, y;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    //create the arrays for splitting
    int L[n1];
    int R[n2];

    //copy the data to these temp arrays
    for (int x = 0; x < n1; x++)
    {
        L[x] = array[left + x];
    }

    for (int y = 0; y < n2; y++)
    {
        R[y] = array[middle + 1 + y];
    }

    //now do the merging
    x = 0;
    y = 0;
    int k = left; //initial index of merged sub-array
    while (x < n1 && y < n2)
    {
        if (L[x] <= R[y])
        {
            array[k] = L[x];
            x++;
        }

        else
        {
            array[k] = R[y];
            y++;
        }
        k++;
    }

    //deal with any remaining elements of L and R
    while (x < n1)
    {
        array[k] = L[x];
        x++;
        k++;
    }

    while (y < n2)
    {
        array[k] = R[y];
        y++;
        k++;
    }
}

void mergeSortHelper(int * array, int left, int right)
{
    if (left < right)
    {
        int m = left + (right - left) / 2;

        //sort the first then second halfs
        mergeSortHelper(array, left, m);
        mergeSortHelper(array, m + 1, right);

        //then merge together
        merge(array, left, m, right);
    }
}

void mergeSort(int* array, long int n) 
{
    mergeSortHelper(array, 0, n-1);
}
