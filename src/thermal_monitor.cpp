#include "thermal_monitor.hpp"

#include <fstream>

float ThermalMonitor::getTemperature()
{
    std::ifstream file(
        "/sys/class/thermal/thermal_zone0/temp");

    int temp = 0;

    file >> temp;

    return temp / 1000.0f;
}