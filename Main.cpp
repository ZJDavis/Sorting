#include "Sorting.h"

using namespace std;

int main() 
{ 
	Timer timer; //create timer
	int dataID = 0;

	for (dataID = 1; dataID < 5; ++dataID)
    {
		for (int size = 100000; size <= 100000000; size = 10 * size)
		{
			//create initial array
			int*array = new int [size];
			srand((unsigned)time(0)); 

			//populate array

			if (dataID = 1) //pseudo-random, many distinct
			{
				for(int i=0; i<size; i++)
				{ 
					array[i] = (rand() % size)+1; 
				} 
			}
			else if (dataID = 2) //pseudo-random, few distinct
			{
				for(int i=0; i<size; i++)
				{ 
					array[i] = (rand() % 100)+1; 
				} 
			}
			else if (dataID = 3) //nearly sorted
			{
				for(int i=0; i<size; i++)
				{ 
					array[i] = (rand() % 100)+(i/100); 
				} 
			}
			else if (dataID = 4) //reverse sorted
			{
				for(int i=0; i<size; i++)
				{ 
					array[i] = size - i; 
				} 
			}
			else {cout << "dataID error.\n";}

			//build algorithm arrays here
			int*arrayQS = new int [size]; //quicksort array
			int*arrayQS2 = new int [size]; //quicksort array 2
			int*arrayMS = new int [size]; //merge sort array
			int*arrayHS = new int [size]; //heapsort array
			int*arrayCS = new int [size]; //counting sort array
			int*arrayTS = new int [size]; //treesort array
			int*array3S = new int [size]; //cubesort array

			for (int i=0; i<size-1; i++) //array copy
			{
				arrayQS[i] = array[i];
				arrayQS2[i] = array[i];
				arrayMS[i] = array[i];
				arrayHS[i] = array[i];
				arrayCS[i] = array[i];
				arrayTS[i] = array[i];
				array3S[i] = array[i];
			}

			timer.start();
			
			//algorithm calls will go here

			timer.stop();

			int tS = timer.elapsedSeconds();
			int tMS = timer.elapsedMilliseconds();
			int tNS = timer.elapsedNanoseconds();
			
			cout << "Time: " << tS << "." << tMS % 1000 << tNS % 1000000 << " seconds.\n";
		}
	// file output will go here
	}
    return 0;
}