#include "Sorting.h"

using namespace std;

chrono::time_point<chrono::system_clock> StartTime;
chrono::time_point<chrono::system_clock> EndTime;
bool bRunning = false;

void Timer::start()
{
    StartTime = chrono::system_clock::now();
    bRunning = true;
}

void Timer::stop()
{
    EndTime = chrono::system_clock::now();
    bRunning = false;
}

double Timer::elapsedSeconds()
{
    chrono::time_point < chrono::system_clock> endTime;
    
    if(bRunning)
    {
        endTime = chrono::system_clock::now();
    }
    else
    {
        endTime = EndTime;
    }
    
    double iS = chrono::duration_cast<chrono::seconds>(endTime - StartTime).count();
    return iS;
}

double Timer::elapsedMilliseconds()
{
    chrono::time_point<chrono::system_clock> endTime;
    
    if(bRunning)
    {
        endTime = chrono::system_clock::now();
    }
    else
    {
        endTime = EndTime;
    }
    
    double iMS = chrono::duration_cast<chrono::milliseconds>(endTime - StartTime).count();
    return iMS;
}

double Timer::elapsedNanoseconds()
{
    chrono::time_point<chrono::system_clock> endTime;
    
    if(bRunning)
    {
        endTime = chrono::system_clock::now();
    }
    else
    {
        endTime = EndTime;
    }
    
    double iNS = chrono::duration_cast<chrono::nanoseconds>(endTime - StartTime).count();
    return iNS;
}



