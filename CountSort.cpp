#include "Sorting.h"

using namespace std;

/*
Counting Sort. A highly time-efficient sorting algorithm discovered outside of CS 350
-Adrian
*/
//NEW IMPLEMENTATION
void countingSort(int *array, long int n){
    //discover the range first
	int range = 0;
	for (int x = 0; x < n; x++)
	{
		if (array[x] >= range)
			range = array[x] + 1;
	}
	
	//range has been found, if highest num is 100, range is now 101
	int* count = new int [range];
    int i;
    int* out =  new int [n];
    /*
    int count[range]={0};
    int i;
    int out[n];
    */
    
    //counting the items
    for(i=0;i<n;i++)
		++count[array[i]];
    
	//counting the frequency
    for(i=1;i<range;i++)
    count[i]+=count[i-1];
    
   
    
    for(i=n-1;i>=0;i--){
        out[count[array[i]]-1]=array[i];
        --count[array[i]];
    }
    
    for(i=0;i<n;i++)
		array[i]=out[i];    
}

//OLD IMPLEMENTATION
//DOESNT WORK
/*void countSort(int * array, long int size)
{
    int maxValue = 0;
    //find the max value first
    for (int x = 1; x < size; x++)
    {
        if (array[x] > maxValue)
            maxValue = array[x];
    }
// original code commented out to avoid errors
//  int sorted[size] = {0}; 
//  int count[maxValue] = {0};
//
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
*/