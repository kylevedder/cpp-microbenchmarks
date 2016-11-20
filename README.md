# C++ Standard Library Microbenchmarks
Microbenchmakring of C++ 11 Standard Library

Currently benchmarks `std::thread`, `std::async`, and `pthread` for both `g++` and `clang++`.

## Benchmark Results:
All values are reported on an Intel® Core™ i5-5200U CPU @ 2.20GHz × 4 running on Ubuntu 16.04.1.

###`g++`:

 Thread type         | Average Run Time (seconds)  |
 --------------------|:-----------|
 `std::thread`       | 0.00450204 |
 `std::async`        | 0.00499383 |
 `pthread`           | 0.00452415 |


 
###`clang++`:


 Thread type         | Average Run Time (seconds)  |
 --------------------|:-----------|
 `std::thread`       | 0.0050485  |
 `std::async`        | 0.00501602 |
 `pthread`           | 0.00506434 |
