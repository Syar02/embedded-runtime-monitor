#include "cpu_monitor.hpp"

#include <fstream>
#include <sstream>
#include <string>

float CpuMonitor::getUsage()
{
    std::ifstream file("/proc/stat");

    std::string line;
    std::getline(file, line);

    std::istringstream ss(line);

    std::string cpu;

    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;

    ss >> cpu
       >> user
       >> nice
       >> system
       >> idle
       >> iowait
       >> irq
       >> softirq
       >> steal;

    unsigned long long idleTime = idle + iowait;

    unsigned long long totalTime =
        user + nice + system +
        idle + iowait +
        irq + softirq + steal;

    unsigned long long totalDelta =
        totalTime - prevTotal;

    unsigned long long idleDelta =
        idleTime - prevIdle;

    prevTotal = totalTime;
    prevIdle = idleTime;

    if (totalDelta == 0)
        return 0.0f;

    return 100.0f *
           (1.0f -
            ((float)idleDelta / totalDelta));
}