#include "Sorting.h"

#include <vector>

/*
	Merge Sort

	Stable comparison sorting algorithm with O(n log n) time complexity.
	This implementation uses one reusable temporary buffer to reduce
	repeated allocations during recursive merging.
*/

namespace
{ //anonymous namespace to keep these functions private to MergeSort
	void merge(int* array, std::vector<int>& temp, long int left, long int middle, long int right)
	{
		long int leftIndex = left;
		long int rightIndex = middle + 1;
		long int tempIndex = left;

		while (leftIndex <= middle && rightIndex <= right)
		{
			if (array[leftIndex] <= array[rightIndex])
			{
				temp[static_cast<std::size_t>(tempIndex)] = array[leftIndex];
				++leftIndex;
			}
			else
			{
				temp[static_cast<std::size_t>(tempIndex)] = array[rightIndex];
				++rightIndex;
			}

			++tempIndex;
		}

		while (leftIndex <= middle)
		{
			temp[static_cast<std::size_t>(tempIndex)] = array[leftIndex];
			++leftIndex;
			++tempIndex;
		}

		while (rightIndex <= right)
		{
			temp[static_cast<std::size_t>(tempIndex)] = array[rightIndex];
			++rightIndex;
			++tempIndex;
		}

		for (long int i = left; i <= right; ++i)
		{
			array[i] = temp[static_cast<std::size_t>(i)];
		}
	}

	void mergeSortHelper(int* array, std::vector<int>& temp, long int left, long int right)
	{
		if (left >= right)
		{
			return;
		}

		const long int middle = left + (right - left) / 2;

		mergeSortHelper(array, temp, left, middle);
		mergeSortHelper(array, temp, middle + 1, right);

		merge(array, temp, left, middle, right);
	}
}

void mergeSort(int* array, long int n)
{
	if (array == nullptr || n <= 1)
	{
		return;
	}

	std::vector<int> temp(static_cast<std::size_t>(n));

	mergeSortHelper(array, temp, 0, n - 1);
}

/* old code
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
	mergeSortHelper(array, 0, n - 1);
}
*/