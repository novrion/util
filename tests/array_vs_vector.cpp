#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;



int main() {

	int ar[100000] = {};
	vector<int> vec;
	int count = 0;

	for (int i = 0; i < 100000; ++i) {
        //ar[i] = i;
		vec.emplace_back(i);
	}

	for (int j = 0; j < 100; ++j) {

		duration<double> time;
		time_point<high_resolution_clock> start_time = high_resolution_clock::now();

		for (int i = 10; i < 100000; ++i) {
			if (vec[i - 1] + vec[i - 2] + vec[i - 3] > count) count += 3;
		}


		time = high_resolution_clock::now() - start_time;
		cout << time.count() << "\n";
	}

    cout << 1;

    return 0;
}