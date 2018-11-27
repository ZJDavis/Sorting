#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <cstdlib> 

using namespace std;

class Timer
{
public:
    void start();
    void stop();
    double elapsedSeconds();
    double elapsedMilliseconds();
    double elapsedNanoseconds();
};


