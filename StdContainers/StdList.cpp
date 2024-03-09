#include "StdList.h"

#include <iostream>
#include <list>
#include <chrono>

#include "Vector3.h"

using namespace std;

void StdList::DoStacking() {
    cout << "Experiment with std::vector." << endl;

    std::list<Vector3> c;
    cout << "Size: " << c.size() << endl;

    c.push_back(Vector3(1, 2, 3));
    c.push_back(Vector3(4, 5, 6));
    c.emplace_back(7, 8, 9);
    c.emplace_back(10, 11, 12);
    cout << "Size: " << c.size() << endl;

    for (auto& v : c) {
        cout << v << endl;
    }

    while (!c.empty()) {
        auto& v = c.back();
        cout << v << endl;
        c.pop_back();
        cout << "Size: " << c.size() << endl;
    }

    c.emplace_back(10, 11, 12);
    cout << "Size: " << c.size() << endl;
    c.pop_back();
    cout << "Size: " << c.size() << endl;
}

void StdList::DoStackTiming(int iterCount, int itemCount) {
    auto start = chrono::high_resolution_clock::now();

    std::list<Vector3> c;
    for (auto i = 0; i < iterCount; i++) {
        for (auto j = 0; j < itemCount; j++) {
            c.emplace_back(1, 2, 3);
        }
        for (auto j = 0; j < itemCount; j++) {
            c.pop_back();
        }
    }

    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "Stacking: std::list Time: " << duration << " milliseconds" << endl;
}

void StdList::DoQueueing() {
    cout << "Queueing with std::list." << endl;

    std::list<Vector3> c;
    c.emplace_back(1, 2, 3);
    c.emplace_back(4, 5, 6);
    c.emplace_back(7, 8, 9);

    while (!c.empty()) {
        cout << c.front() << endl;
        c.pop_front();
    }

    c.emplace_back(1, 2, 3);
    c.emplace_back(4, 5, 6);
    c.emplace_back(7, 8, 9);

    while (!c.empty()) {
        cout << c.front() << endl;
        c.pop_front();
    }
}

void StdList::DoQueueTiming(int iterCount, int itemCount) {
    auto start = chrono::high_resolution_clock::now();

    std::list<Vector3> c;
    for (auto i = 0; i < iterCount; i++) {
        for (auto j = 0; j < itemCount; j++) {
            c.emplace_back(1, 2, 3);
        }
        for (auto j = 0; j < itemCount; j++) {
            c.pop_front();
        }
    }

    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "Queueing: std::list Time: " << duration << " milliseconds" << endl;
}
