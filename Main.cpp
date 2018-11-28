#include "Sorting.h"

using namespace std;

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