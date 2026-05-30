#include "Sorting.h"

#include <algorithm>
#include <vector>

/*
    Cube Sort

    Educational block-based Cube Sort variant.

    This implementation divides the input into small fixed-size blocks
    called "cubes", sorts each cube using insertion sort, and then repeatedly
    merges neighboring sorted cubes until the full array is sorted.

*/

namespace
{
    constexpr long int CubeSize = 32;

    void insertionSortRange(int* array, long int left, long int right)
    {
        for (long int i = left + 1; i <= right; ++i)
        {
            const int key = array[i];
            long int j = i - 1;

            while (j >= left && array[j] > key)
            {
                array[j + 1] = array[j];
                --j;
            }

            array[j + 1] = key;
        }
    }

    void mergeRanges(
        int* array,
        std::vector<int>& temp,
        long int left,
        long int middle,
        long int right)
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
}

void cubeSort(int* array, long int n)
{
    if (array == nullptr || n <= 1)
    {
        return;
    }

    std::vector<int> temp(static_cast<std::size_t>(n));

    // Step 1: Sort each small cube/block.
    for (long int left = 0; left < n; left += CubeSize)
    {
        const long int right = std::min(left + CubeSize - 1, n - 1);
        insertionSortRange(array, left, right);
    }

    // Step 2: Merge sorted cubes until the whole array is sorted.
    for (long int width = CubeSize; width < n; width *= 2)
    {
        for (long int left = 0; left < n; left += 2 * width)
        {
            const long int middle = std::min(left + width - 1, n - 1);
            const long int right = std::min(left + 2 * width - 1, n - 1);

            if (middle < right)
            {
                mergeRanges(array, temp, left, middle, right);
            }
        }
    }
}