#pragma once

class CpuMonitor
{
public:
    float getUsage();

private:
    unsigned long long prevIdle = 0;
    unsigned long long prevTotal = 0;
};