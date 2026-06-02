#pragma once

#include <fstream>
#include <string>

class Logger
{
public:
    Logger(const std::string& filename);

    void write(
        float cpu,
        long usedMem,
        long totalMem,
        float temp);

private:
    std::ofstream file_;
};