#include "Sorting.h"

#include <algorithm>
#include <vector>

using namespace std;

/*
    Counting Sort

    Stable integer sorting algorithm with O(n + k) time complexity,
    where n is the number of elements and k is the range of input values.

    This implementation supports negative integers by offsetting values
    using the minimum value found in the input array.
*/

//NEW IMPLEMENTATION
void countingSort(int *array, long int n){
    //validate first
    if (array == nullptr || n <= 1)
    {
        return;
    }

    int minValue = array[0];
    int maxValue = array[0];

    for (long int i = 1; i < n; ++i)
    {
        minValue = std::min(minValue, array[i]);
        maxValue = std::max(maxValue, array[i]);
    }

    const long int range = static_cast<long int>(maxValue) - minValue + 1;

    std::vector<int> count(static_cast<std::size_t>(range), 0);
    std::vector<int> output(static_cast<std::size_t>(n));

    for (long int i = 0; i < n; ++i)
    {
        ++count[array[i] - minValue];
    }

    for (std::size_t i = 1; i < count.size(); ++i)
    {
        count[i] += count[i - 1];
    }

    for (long int i = n - 1; i >= 0; --i)
    {
        int value = array[i];
        int countIndex = value - minValue;

        output[count[countIndex] - 1] = value;
        --count[countIndex];
    }

    for (long int i = 0; i < n; ++i)
    {
        array[i] = output[i];
    }

    /* old implementation
    //discover the range first
	int range = 0;
	for (int x = 0; x < n; x++)
	{
		if (array[x] >= range)
			range = array[x] + 1;
	}
	
	//range has been found, if highest num is 100, range is now 101
	int* count = new int [range];
    int i;
    int* out =  new int [n];

    
    //counting the items
    for(i=0;i<n;i++)
		++count[array[i]];
    
	//counting the frequency
    for(i=1;i<range;i++)
    count[i]+=count[i-1];
    
    for(i=n-1;i>=0;i--){
        out[count[array[i]]-1]=array[i];
        --count[array[i]];
    }
    
    for(i=0;i<n;i++)
		array[i]=out[i]; 
    */
}