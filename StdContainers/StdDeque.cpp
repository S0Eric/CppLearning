#include "StdDeque.h"

#include <iostream>
#include <deque>
#include <chrono>

#include "Vector3.h"

using namespace std;

void StdDeque::DoStacking() {
    cout << "Stacking with std::deque." << endl;

    std::deque<Vector3> dq;
    cout << "Size: " << dq.size() << endl;
    cout << "Max Size: " << dq.max_size() << endl;

    dq.push_front(Vector3(1, 2, 3));
    dq.push_front(Vector3(4, 5, 6));
    dq.emplace_front(7, 8, 9);
    dq.emplace_front(10, 11, 12);
    cout << "Size: " << dq.size() << endl;

    for (auto& v : dq) {
        cout << v << endl;
    }

    while (!dq.empty()) {
        auto& v = dq.front();
        v.z = -v.z;
        cout << v << endl;
        cout << dq.front() << endl;
        dq.pop_front();
        cout << "Size: " << dq.size() << endl;
    }

    dq.emplace_front(10, 11, 12);
    cout << "Size: " << dq.size() << endl;
    dq.pop_front();
    cout << "Size: " << dq.size() << endl;
}

void StdDeque::DoStackTiming(int iterCount, int itemCount) {
    auto start = chrono::high_resolution_clock::now();

    std::deque<Vector3> dq;
    for (auto i = 0; i < iterCount; i++) {
        for (auto j = 0; j < itemCount; j++) {
            dq.emplace_front(1, 2, 3);
        }
        for (auto j = 0; j < itemCount; j++) {
            dq.pop_front();
        }
    }

    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "Stacking: std::deque Time: " << duration << " milliseconds" << endl;
}

void StdDeque::DoQueueing() {
    cout << "Queueing with std::deque." << endl;

    std::deque<Vector3> c;
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

void StdDeque::DoQueueTiming(int iterCount, int itemCount) {
    auto start = chrono::high_resolution_clock::now();

    std::deque<Vector3> dq;
    for (auto i = 0; i < iterCount; i++) {
        for (auto j = 0; j < itemCount; j++) {
            dq.emplace_back(1, 2, 3);
        }
        for (auto j = 0; j < itemCount; j++) {
            dq.pop_front();
        }
    }

    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "Queueing: std::deque Time: " << duration << " milliseconds" << endl;
}
