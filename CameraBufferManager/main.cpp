#include <iostream>
#include <vector>
#include <memory>

#include "camerabuffermanager.h"

struct MemBufInfo {
    MemBufInfo(uint8_t* ptr, uint32_t size) : ptr(ptr), size(size) {}
    uint8_t* ptr;
    uint32_t size;
};

int main() {
    int allocSizes[] = { 16, 128, 1024, 131072 };
    auto allocSizeCount = sizeof(allocSizes) / sizeof(allocSizes[0]);
    auto memorySize = 1000000;
    auto spBigBlockMemory = std::shared_ptr<uint8_t[]>(new uint8_t[memorySize],
        [](uint8_t* p) { delete[] p; });
    auto bufMgr = std::make_shared<CameraBufferManager>(spBigBlockMemory, memorySize);

    std::vector<MemBufInfo> bufs;
    bufs.reserve(1000);
    auto operationCount = 1000000;
    while (operationCount-- > 0) {
        auto doAlloc = (operationCount % 2) == 0 || bufMgr->remainingOriginalBytes() >= allocSizes[allocSizeCount - 1];
        if (doAlloc) {
            auto allocSize = allocSizes[rand() % allocSizeCount];
            auto pBuf = bufMgr->allocateBuffer(allocSize);
            if (pBuf != nullptr) {
                bufs.emplace_back(pBuf, allocSize);
            }
            else {
                std::cout << "Error allocating " << allocSize << " bytes" << std::endl;
            }
        }
        else {
            auto bufIdx = rand() % bufs.size();
            MemBufInfo& bufInfo = bufs[bufIdx];
            bufMgr->freeBuffer(bufInfo.ptr, bufInfo.size);
            bufs.erase(bufs.begin() + bufIdx);
        }
    }
    std::cout << "Done" << std::endl;
}
