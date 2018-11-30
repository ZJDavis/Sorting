#include "Sorting.h"

using namespace std;

int main() 
{ 
	Timer HStimer; //create heapsort timer
	Timer CStimer; //create countsort timer
	Timer TStimer; //create tree sort timer
	Timer QStimer; //create quick sort timer 1
	Timer MStimer; //create merge sort timer
	int dataID = 0; //handles the switching between the different data set types
	ofstream outputFile;
	outputFile.precision(15); //avoids the scientific notation on large time values (measured in nanoseconds)
	outputFile.open("sortingData.txt");

	for (long int size = 10000; size <= 1000000; size = 10 * size)
	{
		cout << size << " data set\n";

		for (dataID = 1; dataID <= 4; ++dataID)
		{

			//create initial array
			int*array = new int [size];
			srand((unsigned)time(0)); 

			//populate array

			if (dataID == 1) //pseudo-random, many distinct
			{
				cout << "Pseudo-random, many distinct:\n";
				for(int i=0; i<size; i++)
				{ 
					//build an array with the size being the upper limit for random numbers
					array[i] = (rand() % size)+1; 
				}

			}
			else if (dataID == 2) //pseudo-random, few distinct
			{
				cout << "Pseudo-random, few distinct:\n";
				for(int i=0; i<size; i++)
				{ 
					//build an array where the numbers are only 1-100
					array[i] = (rand() % 100)+1; 
				} 
			}
			else if (dataID == 3) //nearly sorted
			{
				cout << "Nearly sorted:\n";
				for(int i=0; i<size; i++)
				{ 
					//build an array that generally has the numbers sorted, but not quite
					array[i] = (rand() % 100)+(i/100); 
				} 
			}
			else if (dataID == 4) //reverse sorted
			{
				cout << "Reverse sorted:\n";
				for(int i=0; i<size; i++)
				{ 
					//build an array were all numbers are sorted from largest to smallest
					array[i] = size - i; 
				} 
			}
			else 
			{
				cout << "dataID error.\n";
			}

			//build algorithm arrays here
			int*arrayHS = new int [size]; //heapsort array
			int*arrayQS = new int [size]; //quicksort array
			int*arrayTS = new int [size]; //treesort array
			int*arrayMS = new int [size]; //merge sort array
			int*arrayCS = new int [size]; //counting sort array

			//loop to gather multiple data points for each set and algorithm combination
			for (int dataPoint=1; dataPoint<=100; ++dataPoint)
			{
				cout << "Datapoint " << dataPoint << ": ";
				for (int i=0; i<size-1; ++i) //array copy
				{
					arrayHS[i] = array[i];
					arrayTS[i] = array[i];
					arrayCS[i] = array[i];
					arrayQS[i] = array[i];
					arrayMS[i] = array[i];
				}
	//MergeSort
				MStimer.start();
				mergeSort(arrayMS, size);
				MStimer.stop();

				outputFile << dataID << " MSArray " << size << " Time " << MStimer.elapsedNanoseconds() << endl;

	//QuickSort
				QStimer.start();
				quickSort(arrayQS, size);
				QStimer.stop();

				outputFile << dataID << " QSArray " << size << " Time " << QStimer.elapsedNanoseconds() << endl;

	//HeapSort
				HStimer.start();
				heapSort(arrayHS, size);
				HStimer.stop();

				outputFile << dataID << " HSArray " << size << " Time " << HStimer.elapsedNanoseconds() << endl;

	//TreeSort
				TStimer.start();
				treeSort(arrayTS, size);
				TStimer.stop();

				outputFile << dataID << " TSArray " << size << " Time " << TStimer.elapsedNanoseconds() << endl;
	//CountSort
				if (size > 1000000) 
				{
					outputFile << dataID << " CSArray " << size << " Time " << endl;
				}
				else
				{
					CStimer.start();
					countingSort(arrayCS, size);
					CStimer.stop();
					outputFile << dataID << " CSArray " << size << " Time " << CStimer.elapsedNanoseconds() << endl;
				}
			}
/* testing sorted order outputs (1 = true, 0 = false)
			cout << "ArrayHS: " << sortCheck(arrayHS,size) << "\n";
			cout << "ArrayTS: " << sortCheck(arrayTS,size) << "\n";
			cout << "ArrayCS: " << sortCheck(arrayCS,size) << "\n";
			cout << "ArrayQS: " << sortCheck(arrayQS,size) << "\n";
			cout << "ArrayMS: " << sortCheck(arrayMS,size) << "\n";
*/
		}
	}

	outputFile.close();
	cout << "Done!\n";
    return 0;
}

bool sortCheck(int * array, long int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		if (array[i] > array[i+1])
			return false;
	}
	return true;
}