#include "Sorting.h"

using namespace std;

//heap sort functions
void heapify(int * array, int n, int i);
void heapSort(int * array, int n);
void countSort(int * arr, int size);

int main() 
{ 
    int size;
    cout<< "how big do you want the array?" << endl;
    cin >> size;

    int*array = new int [size];

    srand((unsigned)time(0)); 

    Timer timer;
     
    for(int i=0; i<size; i++)
    { 
        array[i] = (rand()%100)+1; 
    } 
    cout << endl;

	//build algorithm arrays here
    int*arrayQS = new int [size]; //quicksort array
    int*arrayQS2 = new int [size]; //quicksort array 2
    int*arrayMS = new int [size]; //merge sort array
    int*arrayHS = new int [size]; //heapsort array
    int*arrayCS = new int [size]; //counting sort array
    int*arrayTS = new int [size]; //treesort array
    int*array3S = new int [size]; //cubesort array

    timer.start();
    
	//algorithm calls will go here
	for (int i=0; i<size-1; i++)
	{
		arrayQS[i] = array[i];
	}

    timer.stop();

	int tS = timer.elapsedSeconds();
	int tMS = timer.elapsedMilliseconds();
	int tNS = timer.elapsedNanoseconds();
    
    cout << "Time: " << tS << " seconds \n"; 
    cout << tMS % 1000 << tNS % 1000000 << " nanoseconds.\n";

    return 0;
}

//heapify creates the heap for heapsort. node i
//is the root, and n is the size of the heap
void heapify(int * array, int n, int i)
{
    int biggest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    //logical statements
    if (left < n && array[left] > array[biggest])
    	biggest = left;
    if (right < n && array[right] > array[biggest])
	biggest = right;
    
    if (biggest != i)
    {
        swap(array[i], array[biggest]);
	//recursion
	heapify(array, n, biggest);
    }
}

//main heapSort function
void heapSort(int * array, int n)
{
    //build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n-1; i >= 0; i--)
    {
        //move the current root to the end
	swap(array[0], array[i]);
	heapify(array, i, 0);
    }
}

void countSort(int * array, int size)
{
    int maxValue = 0;
    //find the max value first
    for (int x = 1; x < size; x++)
    {
        if (array[x] > maxValue)
            maxValue = array[x];
    }

    int sorted[size] = {0}; 
    int count[maxValue] = {0};

    for (int j = 0; j < size; j++)
    {
        count[array[j]]++;
    }

    for (int i = 0; i < size; i++)
    {
        count[i] += count[i-1];
    }

    for (int z = size; z >= 0; z--)
    {
        sorted[count[array[z]]] = array[z];
	count[array[z]] = count[array[z]]-1;
    }
}


