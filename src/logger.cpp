#include "logger.hpp"
#include <ctime>

Logger::Logger(
    const std::string& filename)
{
    file_.open(filename);

    file_
        << "timestamp,"
        << "cpu,"
        << "memory_used,"
        << "memory_total,"
        << "temperature\n";

    file_.flush();
}

void Logger::write(
    float cpu,
    long usedMem,
    long totalMem,
    float temp)
{
    std::time_t now =
        std::time(nullptr);
        char timeBuffer[80];
        std::strftime(
            timeBuffer,
            sizeof(timeBuffer),
            "%Y-%m-%d %H:%M:%S",
            std::localtime(&now));

    file_
        << timeBuffer << ","
        << cpu << ","
        << usedMem << ","
        << totalMem << ","
        << temp << "\n";

    file_.flush();
}