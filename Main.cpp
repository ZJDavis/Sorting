#include "Sorting.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>

namespace
{
    constexpr int TrialCount = 5;
    constexpr unsigned int BaseSeed = 350;

    struct InputCase
    {
        std::string name;
        int id;
    };

    struct SortAlgorithm
    {
        std::string name;
        void (*sortFunction)(int*, long int);
    };

    std::vector<int> generateData(long int size, int inputId, unsigned int seed)
    {
        std::vector<int> data(static_cast<std::size_t>(size));
        std::mt19937 generator(seed);

        switch (inputId)
        {
        case 1:
        {
            // Pseudo-random, many distinct values.
            std::uniform_int_distribution<int> distribution(
                -static_cast<int>(size),
                static_cast<int>(size));

            for (long int i = 0; i < size; ++i)
            {
                data[static_cast<std::size_t>(i)] = distribution(generator);
            }

            break;
        }

        case 2:
        {
            // Pseudo-random, few distinct values.
            std::uniform_int_distribution<int> distribution(0, 100);

            for (long int i = 0; i < size; ++i)
            {
                data[static_cast<std::size_t>(i)] = distribution(generator);
            }

            break;
        }

        case 3:
        {
            // Already sorted.
            for (long int i = 0; i < size; ++i)
            {
                data[static_cast<std::size_t>(i)] = static_cast<int>(i);
            }

            break;
        }

        case 4:
        {
            // Reverse sorted.
            for (long int i = 0; i < size; ++i)
            {
                data[static_cast<std::size_t>(i)] = static_cast<int>(size - i);
            }

            break;
        }

        default:
        {
            break;
        }
        }

        return data;
    }

    bool shouldSkipBenchmark(const std::string& algorithmName, const std::string& inputName, long int size)
    {
        const bool isWorstCaseInput =
            inputName == "SortedAscending" ||
            inputName == "ReverseSorted";

        if (algorithmName == "QuickSortNaive" && isWorstCaseInput && size > 10000)
        {
            return true;
        }

        if (algorithmName == "TreeSortNaive" && isWorstCaseInput && size > 10000)
        {
            return true;
        }

        return false;
    }

    std::string skipReason(const std::string& algorithmName, const std::string& inputName, long int size)
    {
        if (shouldSkipBenchmark(algorithmName, inputName, size))
        {
            return "Skipped intentionally; naive algorithm has severe worst-case behavior for this input at this size";
        }

        return "";
    }

    void writeCsvHeader(std::ofstream& outputFile)
    {
        outputFile
            << "algorithm,"
            << "input_type,"
            << "input_id,"
            << "size,"
            << "trial,"
            << "seed,"
            << "min_value,"
            << "max_value,"
            << "value_range,"
            << "time_ns,"
            << "time_ms,"
            << "sorted,"
            << "status,"
            << "notes\n";
    }

    void writeCsvRow(
        std::ofstream& outputFile,
        const std::string& algorithmName,
        const InputCase& inputCase,
        long int size,
        int trial,
        unsigned int seed,
        int minValue,
        int maxValue,
        long long valueRange,
        double timeNs,
        double timeMs,
        bool sorted,
        const std::string& status,
        const std::string& notes)
    {
        outputFile
            << algorithmName << ','
            << inputCase.name << ','
            << inputCase.id << ','
            << size << ','
            << trial << ','
            << seed << ','
            << minValue << ','
            << maxValue << ','
            << valueRange << ','
            << timeNs << ','
            << timeMs << ','
            << (sorted ? "true" : "false") << ','
            << status << ','
            << '"' << notes << '"' << '\n';
    }
}

bool sortCheck(const int* array, long int n)
{
    if (array == nullptr || n <= 1)
    {
        return true;
    }

    for (long int i = 0; i < n - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    const std::vector<long int> sizes =
    {
        1000,
        10000,
        100000,
        1000000
    };

    const std::vector<InputCase> inputCases =
    {
        { "RandomManyDistinct", 1 },
        { "RandomFewDistinct", 2 },
        { "SortedAscending", 3 },
        { "ReverseSorted", 4 }
    };

    const std::vector<SortAlgorithm> algorithms =
    {
        { "HeapSort", heapSort },
        { "CountingSort", countingSort },
        { "MergeSort", mergeSort },
        { "ParallelMergeSort", parallelMergeSort },
        { "QuickSortNaive", quickSortNaive },
        { "QuickSortMedian3", quickSortMedian3 },
        { "TreeSortNaive", treeSortNaive },
        { "TreeSortMultiset", treeSortMultiset },
        { "CubeSort", cubeSort }
    };

    std::ofstream outputFile("sorting_results.csv");
    outputFile.precision(15);

    if (!outputFile)
    {
        std::cerr << "Failed to open sorting_results.csv for writing.\n";
        return 1;
    }

    writeCsvHeader(outputFile);

    for (long int size : sizes)
    {
        std::cout << "Testing size " << size << "...\n";

        for (const InputCase& inputCase : inputCases)
        {
            for (int trial = 1; trial <= TrialCount; ++trial)
            {
                const unsigned int seed =
                    BaseSeed +
                    static_cast<unsigned int>(inputCase.id * 100000) +
                    static_cast<unsigned int>(trial);

                std::vector<int> sourceData = generateData(size, inputCase.id, seed);

                const auto minMax = std::minmax_element(sourceData.begin(), sourceData.end());
                const int minValue = *minMax.first;
                const int maxValue = *minMax.second;
                const long long valueRange =
                    static_cast<long long>(maxValue) - static_cast<long long>(minValue) + 1;

                for (const SortAlgorithm& algorithm : algorithms)
                {
                    if (shouldSkipBenchmark(algorithm.name, inputCase.name, size))
                    {
                        writeCsvRow(
                            outputFile,
                            algorithm.name,
                            inputCase,
                            size,
                            trial,
                            seed,
                            minValue,
                            maxValue,
                            valueRange,
                            0.0,
                            0.0,
                            false,
                            "skipped",
                            skipReason(algorithm.name, inputCase.name, size));

                        continue;
                    }

                    std::vector<int> workingData = sourceData;

                    Timer timer;
                    timer.start();

                    algorithm.sortFunction(workingData.data(), static_cast<long int>(workingData.size()));

                    timer.stop();

                    const bool sorted = sortCheck(
                        workingData.data(),
                        static_cast<long int>(workingData.size()));

                    writeCsvRow(
                        outputFile,
                        algorithm.name,
                        inputCase,
                        size,
                        trial,
                        seed,
                        minValue,
                        maxValue,
                        valueRange,
                        timer.elapsedNanoseconds(),
                        timer.elapsedMilliseconds(),
                        sorted,
                        sorted ? "completed" : "failed",
                        sorted ? "" : "Sort completed but output failed sorted-order validation");
                }
            }
        }
    }

    std::cout << "Done. Results written to sorting_results.csv\n";
    return 0;
}