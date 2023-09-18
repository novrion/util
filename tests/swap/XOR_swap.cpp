/*
    Notice:
    
    This swap is outdated.
    The swap is slightly slower with optimizations (I think).
    The XOR swap also has a fundamental bug when a and b are the same thing (the same memory address). The result is then 0.

*/











#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

static inline void swap_poi(int *a, int *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

static inline void swap_ref(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}

int main() {

    int a = -41;
    int b = 41;

    std::cout << a << " " << b << "\n";

    swap_ref(a, a);

    std::cout << a << " " << b << "\n";

//   int ar[100000];
//   srand((unsigned)time(NULL));

//   for (int j = 0; j < 100000; ++j) {
//     ar[j] = ((rand() * (rand() % 999)) % 2147483640);
//   }

//   duration<double> time =
//       high_resolution_clock::now() - high_resolution_clock::now();
//   time_point<high_resolution_clock> start_time;
//   time_point<high_resolution_clock> stop_time;

//   for (int i = 0; i < 1000; ++i) {

//     start_time = high_resolution_clock::now();

//     for (int j = 0; j < 99995; ++j) {
//       swap_ref(ar[j], ar[j + 1]);
//       swap_ref(ar[j+2], ar[j + 2]);
//       swap_ref(ar[j+4], ar[j + 3]);
//     }

//     stop_time = high_resolution_clock::now();
//     time += start_time - stop_time;
//   }

//   std::cout << time.count() << " s (total)\n";
//   std::cout << time.count() / 1000 << " s (average)\n";

    return 0;
}