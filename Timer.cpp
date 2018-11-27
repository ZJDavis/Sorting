#include "Sorting.h"

using namespace std;

class Timer
{
public:
    void start()
    {
        m_StartTime = chrono::system_clock::now();
        m_bRunning = true;
    }
    
    void stop()
    {
        m_EndTime = chrono::system_clock::now();
        m_bRunning = false;
    }
    
    double elapsedSeconds()
    {
        chrono::time_point < chrono::system_clock> endTime;
        
        if(m_bRunning)
        {
            endTime = chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }
        
        return chrono::duration_cast<chrono::seconds>(endTime - m_StartTime).count();
    }
    
    double elapsedMilliseconds()
    {
        chrono::time_point<chrono::system_clock> endTime;
        
        if(m_bRunning)
        {
            endTime = chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }
        
        return chrono::duration_cast<chrono::milliseconds>(endTime - m_StartTime).count();
    }
    
    double elapsedNanoseconds()
    {
        chrono::time_point<chrono::system_clock> endTime;
        
        if(m_bRunning)
        {
            endTime = chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }
        
        return chrono::duration_cast<chrono::nanoseconds>(endTime - m_StartTime).count();
    }

private:
    chrono::time_point<chrono::system_clock> m_StartTime;
    chrono::time_point<chrono::system_clock> m_EndTime;
    bool m_bRunning = false;
};
