#include <iostream>

#include "StdForwardList.h"
#include "StdDeque.h"
#include "StdVector.h"
#include "StdList.h"

#if false
void* operator new(size_t size) {
    auto ret = malloc(size);
    std::cout << "Allocated " << size << " bytes: " << std::hex << ret << std::dec << std::endl;
    return ret;
}

void operator delete(void* memory, size_t size) {
    std::cout << "Freeing " << size << " bytes: " << std::hex << memory << std::dec << std::endl;
    free(memory);
}
#endif

int main() {
    //StdList::DoBasic();
    //StdForwardList::DoBasics();
    //StdDeque::DoBasic();
    //StdVector::DoBasic();

    auto iterCount = 1000000;
    auto itemCount = 10;

    StdList::DoTiming(iterCount, itemCount);
    StdForwardList::DoTiming(iterCount, itemCount);
    StdDeque::DoTiming(iterCount, itemCount);
    StdVector::DoTiming(iterCount, itemCount);

    StdList::DoTiming(iterCount, itemCount);
    StdForwardList::DoTiming(iterCount, itemCount);
    StdDeque::DoTiming(iterCount, itemCount);
    StdVector::DoTiming(iterCount, itemCount);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
