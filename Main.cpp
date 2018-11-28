#include "Sorting.h"

using namespace std;

int main() 
{ 
	Timer timer; //create timer
	int dataID = 0; //handles the switching between the different data set types
	cout.precision(15); //avoids the scientific notation on large time values (measured in nanoseconds)

	for (dataID = 1; dataID <= 4; ++dataID)
    {
		if (dataID == 1){cout << "Pseudo-random, many distinct:\n";}
		if (dataID == 2){cout << "Pseudo-random, few distinct:\n";}
		if (dataID == 3){cout << "Nearly sorted:\n";}
		if (dataID == 4){cout << "Reverse sorted:\n";}

		for (long int size = 10000; size <= 10000000; size = 10 * size)
		{
			//create initial array
			int*array = new int [size];
			srand((unsigned)time(0)); 

			//populate array

			if (dataID == 1) //pseudo-random, many distinct
			{
				for(int i=0; i<size; i++)
				{ 
					array[i] = (rand() % size)+1; 
				}

			}
			else if (dataID == 2) //pseudo-random, few distinct
			{
				for(int i=0; i<size; i++)
				{ 
					array[i] = (rand() % 100)+1; 
				} 
			}
			else if (dataID == 3) //nearly sorted
			{
				for(int i=0; i<size; i++)
				{ 
					array[i] = (rand() % 100)+(i/100); 
				} 
			}
			else if (dataID == 4) //reverse sorted
			{
				for(int i=0; i<size; i++)
				{ 
					array[i] = size - i; 
				} 
			}
			else 
			{
				cout << "dataID error.\n";
			}

			//build algorithm arrays here
//			int*arrayQS = new int [size]; //quicksort array
//			int*arrayQS2 = new int [size]; //quicksort array 2
//			int*arrayMS = new int [size]; //merge sort array
			int*arrayHS = new int [size]; //heapsort array
//			int*arrayCS = new int [size]; //counting sort array
//			int*arrayTS = new int [size]; //treesort array
//			int*array3S = new int [size]; //cubesort array

			for (int dataPoint=1; dataPoint<=1000; ++dataPoint)
			{
				for (int i=0; i<size-1; ++i) //array copy
				{
	//				arrayQS[i] = array[i];
	//				arrayQS2[i] = array[i];
	//				arrayMS[i] = array[i];
					arrayHS[i] = array[i];
	//				arrayCS[i] = array[i];
	//				arrayTS[i] = array[i];
	//				array3S[i] = array[i];
				}
				//reset timer numbers, just in case

				timer.start();
				heapSort(arrayHS, size); //Try running countSort
				timer.stop();
				
				if (size > 1000000) //nanoseconds will overflow after about 2 seconds
					cout << "Array size: " << size << ", Time: " << timer.elapsedMilliseconds() << " milliseconds.\n";
				else
					cout << "Array size: " << size << ", Time: " << timer.elapsedNanoseconds() << " nanoseconds.\n";
				
				//timer.start();
				//treeSort(arrayTS, size);
				//timer.stop();
				
				
			}
		}
	// file output will go here	
	}
    return 0;
}
