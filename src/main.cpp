#include <iostream>
#include <thread>
#include <chrono>

#include "cpu_monitor.hpp"
#include "memory_monitor.hpp"
#include "thermal_monitor.hpp"
#include "logger.hpp"

int main()
{
    CpuMonitor cpu;
    MemoryMonitor memory;
    ThermalMonitor thermal;

    Logger logger(
        "logs/runtime_log.csv");

    while (true)
    {
        float cpuUsage =
            cpu.getUsage();

        MemoryInfo mem =
            memory.getMemoryInfo();

        float temp =
            thermal.getTemperature();

        std::cout
            << "\n===== Runtime Monitor =====\n";

        std::cout
            << "CPU Usage      : "
            << cpuUsage
            << " %\n";

        std::cout
            << "Memory Usage   : "
            << mem.usedMB
            << " MB / "
            << mem.totalMB
            << " MB\n";

        std::cout
            << "Temperature    : "
            << temp
            << " C\n";

        std::cout
            << "===========================\n";

        logger.write(
            cpuUsage,
            mem.usedMB,
            mem.totalMB,
            temp);

        std::this_thread::sleep_for(
            std::chrono::seconds(1));
    }

    return 0;
}