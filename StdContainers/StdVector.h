#pragma once

class StdVector {
public:
    static void DoStacking();
    static void DoStackTiming(int iterCount, int itemCount);
    static void DoQueueing();
    static void DoQueueTiming(int iterCount, int itemCount);
};
