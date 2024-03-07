#include "StdVector.h"

#include <iostream>
#include <vector>
#include <chrono>

#include "Vector3.h"

using namespace std;

void StdVector::DoBasic() {
    cout << "Experiment with std::vector." << endl;

    std::vector<Vector3> vec;
    vec.reserve(100);
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec.push_back(Vector3(1, 2, 3));
    vec.push_back(Vector3(4, 5, 6));
    vec.emplace_back(7, 8, 9);
    vec.emplace_back(10, 11, 12);
    cout << "Size: " << vec.size() << endl;

    for (auto& v : vec) {
        cout << v << endl;
    }

    while (!vec.empty()) {
        auto& v = vec.back();
        cout << v << endl;
        vec.pop_back();
        cout << "Size: " << vec.size() << endl;
    }

    vec.emplace_back(10, 11, 12);
    cout << "Size: " << vec.size() << endl;
    vec.pop_back();
    cout << "Size: " << vec.size() << endl;
}

void StdVector::DoTiming(int iterCount, int itemCount) {
    auto start = chrono::high_resolution_clock::now();

    std::vector<Vector3> vec;
    vec.reserve(itemCount);
    for (auto i = 0; i < iterCount; i++) {
        for (auto j = 0; j < itemCount; j++) {
            vec.emplace_back(1, 2, 3);
        }
        for (auto j = 0; j < itemCount; j++) {
            vec.pop_back();
        }
    }

    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "vector Time: " << duration << " milliseconds" << endl;
}
