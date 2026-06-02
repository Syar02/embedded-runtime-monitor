#pragma once

struct MemoryInfo
{
    long totalMB;
    long usedMB;
};

class MemoryMonitor
{
public:
    MemoryInfo getMemoryInfo();
};