# Embedded Runtime Monitor

A lightweight C++ runtime monitoring tool for Linux-based embedded systems.

This project was built to monitor system resource usage in real time during compute-intensive workloads such as **DSO-SLAM**, computer vision pipelines, and embedded robotics applications.

---

## Features

* Real-time **CPU usage monitoring**
* Real-time **memory usage tracking**
* Temperature monitoring from Linux thermal sensors
* CSV logging for runtime analysis
* Lightweight terminal output
* Designed for Linux embedded environments

---

## Project Motivation

When running workloads such as SLAM, image processing, or robotics pipelines, it is useful to understand how much system resource is being used during execution.

This project was developed as a simple runtime profiler to answer questions such as:

* How much CPU is consumed during execution?
* How much memory is used over time?
* Does system temperature increase during workload?
* How can runtime metrics be logged for later analysis?

---

## Project Structure

```bash
embedded_runtime_monitor/
├── src/
├── include/
├── logs/
├── CMakeLists.txt
├── build.sh
└── README.md
```

---

## Build

Clone repository:

```bash
git clone https://github.com/Syar02/embedded-runtime-monitor.git
cd embedded-runtime-monitor
```

Build:

```bash
sh build.sh
```

---

## Run

Execute:

```bash
./bin/runtime-monitor
```

---

## Example Output

```bash
===== Runtime Monitor =====
CPU Usage      : 28.86 %
Memory Usage   : 7693 MB / 15782 MB
Temperature    : 27.8 C
===========================
```

---

## CSV Logging

Runtime data is stored automatically in:

```bash
logs/runtime_log.csv
```

Example:

```csv
timestamp,cpu,memory_used,memory_total,temperature
2026-06-02 10:26:40,28.8625,7693,15782,27.8
2026-06-02 10:26:41,25.0635,7699,15782,27.8
```

This makes it easy to visualize data later using Python, Excel, or plotting tools.

---

## Benchmark Test — DSO-SLAM Runtime Monitoring

This runtime monitor was tested while running **DSO-SLAM**.

### Observation Summary

| Metric               |      Result |
| -------------------- | ----------: |
| Idle CPU Usage       |       ~5–7% |
| CPU Usage During DSO |     ~25–33% |
| Peak CPU Usage       |      32.74% |
| Memory Usage         | ~7.6–7.7 GB |
| Temperature          |     ~27.8°C |

### Key Findings

* CPU usage increased significantly during active DSO tracking
* Memory usage remained relatively stable
* Workload appears more **CPU-bound** than memory-bound
* CSV logging allows runtime behavior to be analyzed after execution

---

## Target Use Cases

This project can be used for:

* Embedded Linux runtime monitoring
* Robotics workload profiling
* SLAM benchmarking
* Computer vision performance analysis
* Resource monitoring during long-running applications

---

## Future Improvements

Planned improvements include:

* Runtime graph visualization from CSV logs
* Export plots automatically
* Per-core CPU usage monitoring
* Better thermal sensor detection
* ROS integration
* Benchmark comparison across SLAM workloads

---

## Tech Stack

* C++
* CMake
* Linux system interfaces (`/proc`, `/sys`)
* CSV logging

---

## Author

**Syar**

Embedded systems and runtime performance monitoring for Linux-based robotics and vision workloads.
