#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

static inline void swap_poi(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

static inline void swap_ref(int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}



int main() {

  int ar[100000];
  srand((unsigned)time(NULL));

  for (int j = 0; j < 100000; ++j) {
    ar[j] = ((rand() * (rand() % 999)) % 2147483640);
  }

  duration<double> time =
      high_resolution_clock::now() - high_resolution_clock::now();
  time_point<high_resolution_clock> start_time;
  time_point<high_resolution_clock> stop_time;

  for (int i = 0; i < 10000; ++i) {

    start_time = high_resolution_clock::now();

    for (int j = 0; j < 99995; ++j) {
      swap_poi(&ar[j], &ar[j + 1]);
      swap_poi(&ar[j+2], &ar[j + 2]);
      swap_poi(&ar[j+4], &ar[j + 3]);
    }

    stop_time = high_resolution_clock::now();
    time += start_time - stop_time;
  }

  std::cout << time.count() << " s (total)\n";
  std::cout << time.count() / 10000 << " s (average)\n";

    return 0;
}