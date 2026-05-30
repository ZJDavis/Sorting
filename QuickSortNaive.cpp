#include "Sorting.h"

#include <algorithm>

/*
	Quick Sort

	In-place comparison sorting algorithm. This version uses the final
	element as the pivot, which is simple but vulnerable to poor performance
	on already-sorted or reverse-sorted input.
*/

/* unneeded */
//	void swap(int * a, int * b)
//	{
//		int temp = *a;
//		*a = *b;
//		*b = temp;
//	}


namespace
{
	long int quickSortPartition(int * array, long int low, long int high)
	{
		const int pivot = array[high]; //pivot
		long int i = (low - 1); //smaller element

		for (long int x = low; x < high; x++)
		{
			if (array[x] <= pivot)
			{
				i++;
				std::swap(&array[i], &array[x]);
			}
		}

		swap(&array[i + 1], &array[high]);
		return (i + 1);
	}

	void quickSortHelper(int* array, int low, int high)
	{
		if (low >= high)
		{
			return;
		}
		const long int partitionIndex = quickSortPartition(array, low, high);

		//sort items before partition and after partition
		quickSortHelper(array, low, part_index - 1);
		quickSortHelper(array, part_index + 1, high);
	}
}

void quickSort(int* array, long int n)
{
	if (array == nullptr || n <= 1)
	{
		return;
	}

	quickSortHelper(array, 0, n - 1);
}
