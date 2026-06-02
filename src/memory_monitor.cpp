#include "memory_monitor.hpp"

#include <fstream>
#include <string>

MemoryInfo MemoryMonitor::getMemoryInfo()
{
    std::ifstream file("/proc/meminfo");

    std::string label;

    long total = 0;
    long available = 0;

    while (file >> label)
    {
        if (label == "MemTotal:")
        {
            file >> total;
        }
        else if (label == "MemAvailable:")
        {
            file >> available;
        }
        else
        {
            std::string skip;
            std::getline(file, skip);
        }
    }

    MemoryInfo info;

    info.totalMB = total / 1024;
    info.usedMB = (total - available) / 1024;

    return info;
}