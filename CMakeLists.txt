cmake_minimum_required(VERSION 3.10)

project(embedded_runtime_monitor)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(runtime-monitor
    src/main.cpp
    src/cpu_monitor.cpp
    src/memory_monitor.cpp
    src/thermal_monitor.cpp
    src/logger.cpp
)