#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <cstdlib> 

using namespace std;

//algorithms (modify the definitions if needed)

//heap sort functions
void heapify(int * array, long int n, long int i);
void heapSort(int * array, long int n);

void countSort(int * array, long int n);

void treeSort(int* array, long int n);

void cubeSort(int* array);

void quickSort(int* array);

void quickSort2(int* array);

void mergeSort(int* array);

class Timer
{
public:
    void start();
    void stop();
    double elapsedSeconds();
    double elapsedMilliseconds();
    double elapsedNanoseconds();
};


