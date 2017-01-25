# C++ Standard Library Microbenchmarks
Microbenchmakring of C++ 11 Standard Library

Currently benchmarks `std::thread`, `std::async`, and `pthread` for both `g++` and `clang++`.

Here is a breakdown on the performance given each optimization level. You should read more 
information about optimization flags for [`g++`](https://wiki.gentoo.org/wiki/GCC_optimization#-O) 
and [`clang++`](http://clang.llvm.org/docs/CommandGuide/clang.html#code-generation-options) to get
a better understanding of the implications of these flags.

## Benchmark Results:

Benckmarks are reported on two systems:
 - **i5 5200**: Intel® Core™ i5-5200U CPU @ 2.20GHz × 4 running on Ubuntu 16.04.1
   - `g++` version `(Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609`
   - `clang++` version `version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)`
 - **i5 6300**: Intel® Core™ i5-6300U CPU @ 2.40GHz × 4 running on Ubuntu 16.04.1
   - `g++` version `(Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609`
   - `clang++` version `version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)`

All values are average run times in seconds. Please note that times fluctuate between runs and 
thus should be treated as ballpark estimates rather than exact numbers.

####`g++` with `-O2` set:

 Thread type         | i5 5200     | i5 6300     |
 --------------------|:------------|:------------|
 `std::thread`       | 0.00427142  | 0.00434303  |
 `std::async`        | 0.00413641  | 0.00436270  |
 `pthread`           | 0.00001201  | 0.00001146  |
 `std::vector`       |   | 0.0000000239          |
 `std::map`          |   | 0.0000000262          |

####`g++` with `-O3` set:

 Thread type         | i5 5200     | i5 6300     |
 --------------------|:------------|:------------|
 `std::thread`       | 0.00412891  | 0.00437466  |
 `std::async`        | 0.00412404  | 0.00430873  |
 `pthread`           | 0.00001286  | 0.00001124  |
 `std::vector`       |   | 0.0000000253          |
 `std::map`          |   | 0.0000000263          |

####`g++` with `-Ofast` set (breaks language compliance):

 Thread type         | i5 5200     | i5 6300     |
 --------------------|:------------|:------------|
 `std::thread`       | 0.00412911  | 0.00441190  |
 `std::async`        | 0.00412873  | 0.00435164  |
 `pthread`           | 0.00001146  | 0.00001107  |
 `std::vector`       |   | 0.0000000231          |
 `std::map`          |   | 0.0000000581          |


####`clang++` with `-O2` set:

 Thread type         | i5 5200     | i5 6300     |
 --------------------|:------------|:------------|
 `std::thread`       | 0.00413400  | 0.00438218  |
 `std::async`        | 0.00453824  | 0.00441700  |
 `pthread`           | 0.00439311  | 0.00427437  |
 `std::vector`       |   | 0.0000000441          |
 `std::map`          |   | 0.0000000445          |

####`clang++` with `-O3` set:

 Thread type         | i5 5200     | i5 6300     |
 --------------------|:------------|:------------|
 `std::thread`       | 0.00424165  | 0.00435809  |
 `std::async`        | 0.00422098  | 0.00439395  |
 `pthread`           | 0.00417244  | 0.00427716  |
 `std::vector`       |   | 0.0000000258          |
 `std::map`          |   | 0.0000000615          |

####`clang++` with `-Ofast` set (breaks language compliance):

 Thread type         | i5 5200     | i5 6300     |
 --------------------|:------------|:------------|
 `std::thread`       | 0.00415550  | 0.00444967  |
 `std::async`        | 0.00414783  | 0.00433502  |
 `pthread`           | 0.00001147  | 0.00001173  |
 `std::vector`       |   | 0.0000000229          |
 `std::map`          |   | 0.0000000310          |
