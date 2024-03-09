#include "StdVector.h"

#include <iostream>
#include <vector>
#include <chrono>

#include "Vector3.h"

using namespace std;

void StdVector::DoStacking() {
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

void StdVector::DoStackTiming(int iterCount, int itemCount) {
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

    cout << "Stacking: std::vector Time: " << duration << " milliseconds" << endl;
}

void StdVector::DoQueueing() {
    cout << "Queueing with std::vector." << endl;

    std::vector<Vector3> c;
    c.reserve(20);
    c.emplace_back(1, 2, 3);
    c.emplace_back(4, 5, 6);
    c.emplace_back(7, 8, 9);

    while (!c.empty()) {
        cout << c.front() << endl;
        c.erase(c.begin());
    }

    c.emplace_back(1, 2, 3);
    c.emplace_back(4, 5, 6);
    c.emplace_back(7, 8, 9);

    while (!c.empty()) {
        cout << c.front() << endl;
        c.erase(c.begin());
    }
}

void StdVector::DoQueueTiming(int iterCount, int itemCount) {
    auto start = chrono::high_resolution_clock::now();

    std::vector<Vector3> c;
    for (auto i = 0; i < iterCount; i++) {
        for (auto j = 0; j < itemCount; j++) {
            c.emplace_back(1, 2, 3);
        }
        for (auto j = 0; j < itemCount; j++) {
            c.erase(c.begin());
        }
    }

    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "Queueing: std::vector Time: " << duration << " milliseconds" << endl;
}
