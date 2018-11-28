#include "Sorting.h"

using namespace std;

int main() 
{ 
	Timer HStimer; //create heapsort timer
	Timer CStimer; //create countsort timer
	Timer TStimer; //create tree sort timer
	Timer cubeTimer; //create cube sort timer
	Timer QStimer; //create quick sort timer 1
	Timer QStimer2; //create quick sort timer 2
	Timer MStimer; //create merge sort timer
	int dataID = 0; //handles the switching between the different data set types
	cout.precision(15); //avoids the scientific notation on large time values (measured in nanoseconds)
	ofstream outputFile;
	outputFile.open("sortingData.txt");

	for (long int size = 10000; size <= 10000000; size = 10 * size)
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
			int*arrayQS = new int [size]; //quicksort array
			int*arrayQS2 = new int [size]; //quicksort array 2
			int*arrayMS = new int [size]; //merge sort array
			int*arrayHS = new int [size]; //heapsort array
			int*arrayCS = new int [size]; //counting sort array
			int*arrayTS = new int [size]; //treesort array
			int*array3S = new int [size]; //cubesort array

			//loop to gather multiple data points for each set and algorithm combination
			for (int dataPoint=1; dataPoint<=10; ++dataPoint)
			{
				for (int i=0; i<size-1; ++i) //array copy
				{
					arrayHS[i] = array[i];
					arrayCS[i] = array[i];
					arrayTS[i] = array[i];
					array3S[i] = array[i];
					arrayQS[i] = array[i];
					arrayQS2[i] = array[i];
					arrayMS[i] = array[i];
				}
	//HeapSort
				HStimer.start();
				heapSort(arrayHS, size);
				HStimer.stop();
				/*
				if (size > 1000000) //nanoseconds will overflow after about 2 seconds
					cout << "Array size: " << size << ", Time: " << HStimer.elapsedMilliseconds() << " milliseconds.\n";
				else*/
					outputFile << dataID << " HSArray " << size << " Time " << HStimer.elapsedNanoseconds() << endl;
	//TreeSort
				if (size > 10000 && dataID == 4) 
				{
					outputFile << dataID << "TSArray " << size << " Time " << endl;
				}
				else if (size > 1000000 && dataID == 3) 
				{
					outputFile << dataID << "TSArray " << size << " Time " << endl;
				}
				else
				{
					TStimer.start();
					treeSort(arrayTS, size);
					TStimer.stop();
					outputFile << dataID << "TSArray " << size << " Time " << TStimer.elapsedNanoseconds() << endl;
				}
	//CountSort
				if (size > 1000000) 
				{
					outputFile << dataID << "CSArray " << size << " Time " << endl;
				}
				else
				{
					CStimer.start();
					countingSort(arrayCS, size);
					CStimer.stop();
					outputFile << dataID << "CSArray " << size << " Time " << CStimer.elapsedNanoseconds() << endl;
				}
			}
		}
	}

	outputFile.close();
	cout << "Done!\n";
    return 0;
}