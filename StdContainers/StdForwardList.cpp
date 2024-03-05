#include "StdForwardList.h"

#include <iostream>
#include <forward_list>
#include <memory>
#include <chrono>

#include "Vector3.h"

using namespace std;

void StdForwardList::DoBasics() {
    cout << "Experiment with std::forward_list." << endl;

    auto i = 5;
    cout << hex << &i << dec << endl;
    auto pV = new Vector3(9, 99, 999);

    cout << "sizeof(Vector3): " << sizeof(Vector3) << endl;
    cout << "sizeof(pV): " << sizeof(pV) << endl;

    auto fl = forward_list<Vector3>();

    fl.push_front(Vector3(1, 2, 3));
    fl.push_front(Vector3(4, 5, 6));
    fl.push_front(Vector3(7, 8, 9));
    fl.emplace_front(1, 2, 3);
    fl.emplace_front(4, 5, 6);
    fl.emplace_front(7, 8, 9);

    for (auto &v : fl) {
        cout << v << endl;
    }

    while (!fl.empty()) {
        auto& v = fl.front();
        cout << v << endl;
        fl.pop_front();
    }
}

// Since forward_list is a linked list, it has to allocate and free a small header structure every time something is pushed or popped from the list. Is there any way to use forward_list in a way that doesn't cause any memory allocation and freeing, or is there a better std container class that efficiently supports pushing and popping from the front without causing memory operations?

void StdForwardList::DoTiming(int iterCount, int itemCount) {
    auto start = chrono::high_resolution_clock::now();

    std::forward_list<Vector3> fl;
    for (auto i = 0; i < iterCount; i++) {
        for (auto j = 0; j < itemCount; j++) {
            fl.emplace_front(1, 2, 3);
        }
        for (auto j = 0; j < itemCount; j++) {
            fl.pop_front();
        }
    }

    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "forward_list Time: " << duration << " milliseconds" << endl;
}
