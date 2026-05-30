#include "Sorting.h"

#include <algorithm>

/*
    Quick Sort

    In-place comparison sorting algorithm using median-of-three pivot
    selection and reduced recursion depth.
*/

namespace
{
    long int medianOfThree(int* array, long int low, long int high)
    {
        const long int middle = low + (high - low) / 2;

        if (array[middle] < array[low])
        {
            std::swap(array[middle], array[low]);
        }

        if (array[high] < array[low])
        {
            std::swap(array[high], array[low]);
        }

        if (array[high] < array[middle])
        {
            std::swap(array[high], array[middle]);
        }

        return middle;
    }

    long int quickSortPartition(int* array, long int low, long int high)
    {
        const long int pivotIndex = medianOfThree(array, low, high);

        std::swap(array[pivotIndex], array[high]);

        const int pivot = array[high];
        long int smallerIndex = low - 1;

        for (long int currentIndex = low; currentIndex < high; ++currentIndex)
        {
            if (array[currentIndex] <= pivot)
            {
                ++smallerIndex;
                std::swap(array[smallerIndex], array[currentIndex]);
            }
        }

        std::swap(array[smallerIndex + 1], array[high]);
        return smallerIndex + 1;
    }

    void quickSortHelper(int* array, long int low, long int high)
    {
        while (low < high)
        {
            const long int partitionIndex = quickSortPartition(array, low, high);

            const long int leftSize = partitionIndex - low;
            const long int rightSize = high - partitionIndex;

            if (leftSize < rightSize)
            {
                quickSortHelper(array, low, partitionIndex - 1);
                low = partitionIndex + 1;
            }
            else
            {
                quickSortHelper(array, partitionIndex + 1, high);
                high = partitionIndex - 1;
            }
        }
    }
}

void quickSortMedian3(int* array, long int n) 
{
    if (array == nullptr || n <= 1)
    {
        return;
    }

    quickSortHelper(array, 0, n - 1);
}