# C++ Standard Library Microbenchmarks
Microbenchmakring of C++ 11 Standard Library

Currently benchmarks `std::thread`, `std::async`, and `pthread` for both `g++` and `clang++`.

## Benchmark Results:
All values are reported on an Intel® Core™ i5-5200U CPU @ 2.20GHz × 4 running on Ubuntu 16.04.1 
using `g++` version `(Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609` and `clang++` 
version `version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)`.

### Note on Optimization Flags:
Here is a breakdown on the performance given each optimization level. You should read more 
information about optimization flags for [`g++`](https://wiki.gentoo.org/wiki/GCC_optimization#-O) 
and [`clang++`](http://clang.llvm.org/docs/CommandGuide/clang.html#code-generation-options) to get
a better understanding of the implications of these flags.

####`g++` with `-O2` set:

 Thread type         | Average Run Time (seconds)  |
 --------------------|:------------|
 `std::thread`       | 0.00427142  |
 `std::async`        | 0.00413641  |
 `pthread`           | 0.00001201  |

####`g++` with `-O3` set:

 Thread type         | Average Run Time (seconds)  |
 --------------------|:------------|
 `std::thread`       | 0.00412891  |
 `std::async`        | 0.00412404  |
 `pthread`           | 0.00001286  |

####`g++` with `-Ofast` set (Breaks language compliance!):

 Thread type         | Average Run Time (seconds)  |
 --------------------|:------------|
 `std::thread`       | 0.00412911  |
 `std::async`        | 0.00412873  |
 `pthread`           | 0.00001146  |


####`clang++` with `-O2` set:

 Thread type         | Average Run Time (seconds)  |
 --------------------|:------------|
 `std::thread`       | 0.00413400  |
 `std::async`        | 0.00453824  |
 `pthread`           | 0.00439311  |

####`clang++` with `-O3` set:

 Thread type         | Average Run Time (seconds)  |
 --------------------|:------------|
 `std::thread`       | 0.00424165  |
 `std::async`        | 0.00422098  |
 `pthread`           | 0.00417244  |

####`clang++` with `-Ofast` set (Breaks language compliance!):

 Thread type         | Average Run Time (seconds)  |
 --------------------|:------------|
 `std::thread`       | 0.00415550  |
 `std::async`        | 0.00414783  |
 `pthread`           | 0.00001147  |
