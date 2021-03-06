// Copyright 2016 kyle@vedder.io
//
// This software is free: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License Version 3,
// as published by the Free Software Foundation.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// Version 3 in the file COPYING that came with this distribution.
// If not, see <http://www.gnu.org/licenses/>.
// ========================================================================

#include <iostream>
#include <thread>
#include <future>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <map>
#include <vector>

using std::cout;
using std::thread;
using std::async;
using std::launch;
using std::future;
using std::map;
using std::vector;

static const int kNumTrials = 1000;
static const int kNumWorkerCalculations = 50000;

double GetMonotonicTime() {
  timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  const double time =
    static_cast<double>(ts.tv_sec) + static_cast<double>(ts.tv_nsec)*(1.0E-9);
  return time;
}

// Does not need to do special join() functionality.
double worker_function_thread() {
  double answer = 0;
  for (int i = 0; i < kNumWorkerCalculations; ++i) {
    answer += sin(i) + tan(i);
  }
  return answer;
}

// Takes care of joining the pthread().
void* worker_function_pthread(void* vargp) {
  double answer = 0;
  for (int i = 0; i < kNumWorkerCalculations; ++i) {
    answer += sin(i) + tan(i);
  }
  *((double*)vargp) = 42;
  pthread_exit(vargp);
}

int main() {
  cout << "Starting benchmarks!\n";

  // std::thread
  cout << "\033[1;34mStarting std::thread benchmark\033[0;0m\n";
  double total_delta = 0.0;
  for (int i = 0; i < kNumTrials; ++i) {
    double start_time = GetMonotonicTime();
    thread t1(worker_function_thread);
    t1.join();
    double end_time = GetMonotonicTime();
    total_delta += end_time - start_time;
  }
  cout << "std::thread benchmark done!\n";
  cout << "std::thread average time: \t" << total_delta / static_cast<double>(kNumTrials)
       << "\n";

  // std::async
  cout << "\033[1;34mStarting std::async benchmark\033[0;0m\n";
  total_delta = 0.0;
  for (int i = 0; i < kNumTrials; ++i) {
    double start_time = GetMonotonicTime();
    future<double> future = std::async(launch::async, worker_function_thread);
    future.get();
    double end_time = GetMonotonicTime();
    total_delta += end_time - start_time;
  }
  cout << "std::async benchmark done!\n";
  cout << "std::async average time: \t" << total_delta / static_cast<double>(kNumTrials)
       << "\n";

  // pthread
  total_delta = 0;
  cout << "\033[1;34mStarting pthread benchmark\033[0;0m\n";
  for (int i = 0; i < kNumTrials; ++i) {
    double start_time = GetMonotonicTime();
    pthread_t thread;
    pthread_attr_t attr;
    int rc;
    double t = 0;
    void* status;

    // Initialize and set thread detached attribute
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    rc = pthread_create(&thread, &attr, worker_function_pthread, &t);
    if (rc) {
      cout << "ERROR; return code from pthread_create() is " << rc << "\n";
    }


    // Free attribute and wait for the other threads
    pthread_attr_destroy(&attr);
    rc = pthread_join(thread, &status);
    if (rc) {
      cout << "ERROR; return code from pthread_join() is " << rc << "\n";
    }
    double end_time = GetMonotonicTime();
    total_delta += end_time - start_time;
  }
  cout << "pthread benchmark done!\n";
  cout << "pthread average time: \t\t" << total_delta / static_cast<double>(kNumTrials)
       << "\n";

  // std::vector
  total_delta = 0;
  cout << "\033[1;34mStarting vector benchmark\033[0;0m\n";
  vector<int> vector;
  vector.push_back(0);
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);
  vector.push_back(4);
  int sum = 0;
  for (int i = 0; i < kNumTrials; ++i) {
    double start_time = GetMonotonicTime();
    int value = vector[3];
    sum += value;
    double end_time = GetMonotonicTime();
    total_delta += end_time - start_time;
  }
  cout << "vector benchmark done!\n";
  cout << "vector average time: \t\t" << total_delta / static_cast<double>(kNumTrials)
       << "\n";

  // std::map
  total_delta = 0;
  cout << "\033[1;34mStarting vector benchmark\033[0;0m\n";
  map<int, int> map;
  map.insert(std::pair<int, int>(0, 0));
  map.insert(std::pair<int, int>(1, 1));
  map.insert(std::pair<int, int>(2, 2));
  map.insert(std::pair<int, int>(3, 3));
  map.insert(std::pair<int, int>(4, 4));
  sum = 0;
  for (int i = 0; i < kNumTrials; ++i) {
    double start_time = GetMonotonicTime();
    int value = map[3];
    sum += value;
    double end_time = GetMonotonicTime();
    total_delta += end_time - start_time;
  }
  cout << "map benchmark done!\n";
  cout << "map average time: \t\t" << total_delta / static_cast<double>(kNumTrials)
       << "\n";
}

