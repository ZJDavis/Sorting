#include "Sorting.h"

#include <algorithm>

/*
	Naive Quick Sort

	Uses the final element as the pivot. This version is intentionally kept
	as a benchmark comparison because it performs poorly on already-sorted
	and reverse-sorted input.
*/

namespace
{
	long int quickSortNaivePartition(int* array, long int low, long int high)
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

	void quickSortNaiveHelper(int* array, long int low, long int high)
	{
		if (low >= high)
		{
			return;
		}
		const long int partitionIndex = quickSortNaivePartition(array, low, high);

		//sort items before partition and after partition
		quickSortNaiveHelper(array, low, part_index - 1);
		quickSortNaiveHelper(array, part_index + 1, high);
	}
}

void quickSortNaive(int* array, long int n)
{
	if (array == nullptr || n <= 1)
	{
		return;
	}

	quickSortNaiveHelper(array, 0, n - 1);
}
