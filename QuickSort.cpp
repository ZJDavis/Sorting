#include "Sorting.h"

using namespace std;

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int quickSortPartition(int * array, int low, int high)
{
	int pivot = array[high]; //pivot
	int i = (low - 1); //smaller element

	for (int x = low; x <= high - 1; x++)
	{
		if (array[x] <= pivot)
		{
			i++;
			swap(&array[i], &array[x]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSortHelper(int * array, int low, int high)
{
	if (low < high)
	{
		int part_index = quickSortPartition(array, low, high);

		//sort items before partition and after partition
		quickSortHelper(array, low, part_index - 1);
		quickSortHelper(array, part_index + 1, high);
	}
}

void quickSort(int* array, long int n)
{
	quickSortHelper(array, 0, n - 1);
}
