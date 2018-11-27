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
    timer.start();
     
    for(int i=0; i<size; i++)
    { 
        array[i] = (rand()%100)+1; 
    } 
    cout << endl;
    

    timer.stop();
    
    cout << "Time: " << timer.elapsedSeconds() << "seconds \n"; 
    cout << timer.elapsedNanoseconds() << endl;
    return 0;
}