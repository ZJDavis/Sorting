#include "Sorting.h"

#include <algorithm>
#include <future>
#include <thread>
#include <vector>

/*
    Parallel Merge Sort

    Multithreaded merge sort implementation.

    The algorithm recursively sorts the left and right halves of the array.
    For sufficiently large partitions, one half is sorted asynchronously
    while the other is sorted on the current thread. Recursion depth is
    limited based on hardware concurrency to avoid creating too many threads.

    Time complexity: O(n log n)
    Space complexity: O(n)
*/

namespace
{
    constexpr long int MinParallelSize = 50'000;

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

    unsigned int calculateMaxDepth()
    {
        unsigned int threadCount = std::thread::hardware_concurrency();

        if (threadCount == 0)
        {
            threadCount = 2;
        }

        unsigned int depth = 0;

        while (threadCount > 1)
        {
            threadCount /= 2;
            ++depth;
        }

        return depth;
    }

    void parallelMergeSortHelper(
        int* array,
        std::vector<int>& temp,
        long int left,
        long int right,
        unsigned int depthRemaining)
    {
        if (left >= right)
        {
            return;
        }

        const long int middle = left + (right - left) / 2;
        const long int size = right - left + 1;

        if (depthRemaining > 0 && size >= MinParallelSize)
        {
            auto leftTask = std::async(
                std::launch::async,
                parallelMergeSortHelper,
                array,
                std::ref(temp),
                left,
                middle,
                depthRemaining - 1);

            parallelMergeSortHelper(
                array,
                temp,
                middle + 1,
                right,
                depthRemaining - 1);

            leftTask.get();
        }
        else
        {
            parallelMergeSortHelper(array, temp, left, middle, 0);
            parallelMergeSortHelper(array, temp, middle + 1, right, 0);
        }

        mergeRanges(array, temp, left, middle, right);
    }
}

void parallelMergeSort(int* array, long int n)
{
    if (array == nullptr || n <= 1)
    {
        return;
    }

    std::vector<int> temp(static_cast<std::size_t>(n));
    const unsigned int maxDepth = calculateMaxDepth();

    parallelMergeSortHelper(array, temp, 0, n - 1, maxDepth);
}