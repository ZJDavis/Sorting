#include "Sorting.h"

using namespace std;

/*
Counting Sort. A highly time-efficient sorting algorithm discovered outside of CS 350
-Adrian
*/

void countSort(int * array, long int size)
{
    int maxValue = 0;
    //find the max value first
    for (int x = 1; x < size; x++)
    {
        if (array[x] > maxValue)
            maxValue = array[x];
    }

/* original code commented out to avoid errors
    int sorted[size] = {0}; 
    int count[maxValue] = {0};
*/
    //added this modified code to remove errors in compile -zack
    int * sorted = new int [size]; 
    int * count = new int [maxValue];


    for (int j = 0; j < size; j++)
    {
        count[array[j]]++;
    }

    for (int i = 0; i < size; i++)
    {
        count[i] += count[i-1];
    }

    for (int z = size; z >= 0; z--)
    {
        sorted[count[array[z]]] = array[z];
	count[array[z]] = count[array[z]]-1;
    }
}
