#ifndef SORTING_H
#define SORTING_H

#include <chrono>

void heapSort(int* array, long int n);

void countingSort(int* array, long int n);

void mergeSort(int* array, long int n);
void parallelMergeSort(int* array, long int n);

void quickSortNaive(int* array, long int n);
void quickSortMedian3(int* array, long int n);

void treeSortNaive(int* array, long int n);
void treeSortMultiset(int* array, long int n);

void cubeSort(int* array, long int n);

bool sortCheck(const int* array, long int n);

class Timer
{
public:
    void start();
    void stop();

    double elapsedSeconds() const;
    double elapsedMilliseconds() const;
    double elapsedNanoseconds() const;

private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    bool running = false;
};

#endif