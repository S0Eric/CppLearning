#include <iostream>

#include "StdForwardList.h"
#include "StdDeque.h"
#include "StdVector.h"

//#include "LogMemoryOperations.h"

int main() {
    //StdForwardList::DoBasics();
    //StdDeque::DoBasic();
    //StdVector::DoBasic();

    //StdForwardList::DoTiming(3, 2);
    //StdDeque::DoTiming(3, 2);
    //StdVector::DoTiming(3, 2);

    auto iterCount = 1000000;
    auto itemCount = 10;

    StdForwardList::DoTiming(iterCount, itemCount);
    StdDeque::DoTiming(iterCount, itemCount);
    StdVector::DoTiming(iterCount, itemCount);

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
