#include "Sorting.h"

void Timer::start()
{
    startTime = std::chrono::steady_clock::now();
    running = true;
}

void Timer::stop()
{
    endTime = std::chrono::steady_clock::now();
    running = false;
}

double Timer::elapsedSeconds() const
{
    const auto currentEndTime = running
        ? std::chrono::steady_clock::now()
        : endTime;

    return std::chrono::duration<double>(currentEndTime - startTime).count();
}

double Timer::elapsedMilliseconds() const
{
    const auto currentEndTime = running
        ? std::chrono::steady_clock::now()
        : endTime;

    return std::chrono::duration<double, std::milli>(currentEndTime - startTime).count();
}

double Timer::elapsedNanoseconds() const
{
    const auto currentEndTime = running
        ? std::chrono::steady_clock::now()
        : endTime;

    return std::chrono::duration<double, std::nano>(currentEndTime - startTime).count();
}