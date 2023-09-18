#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <string>
using namespace std;


const int MEMBER_COUNT = 6;

static inline int GetRandom( const int size ) {
    srand( (unsigned)time( NULL ) );
    return (rand()) % size;
}

int main() {

    int count = 0;
    int random;
    vector<string> vec = { "1", "2", "3", "4", "5", "6" };

    while (true) {

        if (!vec.size()) break;

        random = GetRandom( vec.size() );
        cout << vec[random] << " ";

        vec.erase( vec.begin() + random );
        if (++count % 2 == 0) cout << "\n";
    }



    return 0;
}